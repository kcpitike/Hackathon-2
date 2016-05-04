#include "Solidification2.h"

template<>
InputParameters validParams<Solidification2>()
{
  InputParameters params = validParams<Kernel>();
  params.addRequiredCoupledVar("Phi", "The phase field parameter");
  params.addRequiredCoupledVar("U", "The dimensionless temperature field");
  params.addParam<Real>("Eps_m", 1.0, "Epsilon_m");
  params.addParam<Real>("m", 1.0, "Integer");
  params.addParam<Real>("W0", 1.0, "Interface thickness constant");
  params.addParam<Real>("th0", 0.0, "offset azimuthal angle");
  params.addParam<Real>("tau0", 1.0, "time constant");
  params.addParam<Real>("offset", 0.000001, "offset");
  return params;
}

Solidification2::Solidification2(const InputParameters & parameters)
  :Kernel(parameters),
  _Phi(coupledValue("Phi")),
  _Phi_grad(coupledGradient("Phi")),
  _U(coupledValue("U")),
  _Eps_m(getParam<Real>("m")),
  _m(getParam<Real>("m")),
  _W0(getParam<Real>("W0")),
  _th0(getParam<Real>("th0")),
  _tau0(getParam<Real>("tau0")),
  _offset(getParam<Real>("offset"))
{

}

Real
Solidification2::computeQpResidual()
{
  return  (0.5 * (15.9566 * _U[_qp] - _Phi[_qp] - 2.0 * _U[_qp] * 15.9566 * _Phi[_qp] * _Phi[_qp] + _U[_qp] * 15.9566 * _Phi[_qp] * _Phi[_qp] * _Phi[_qp] * _Phi[_qp]) * _test[_i][_qp] )   ;
}
