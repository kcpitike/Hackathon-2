#include "Solidification2.h"

template<>
InputParameters validParams<Solidification2>()
{
  InputParameters params = validParams<Kernel>();
  params.addRequiredCoupledVar("Phi", "The phase field parameter");
  params.addRequiredCoupledVar("U", "The dimensionless temperature field");
  params.addRequiredCoupledVar("PhiWdx", "split phase 1 of material");
  params.addRequiredCoupledVar("PhiWdy", "split phase 2 of material");
  params.addParam<Real>("Eps_m", 1.0, "Epsilon_m");
  params.addParam<Real>("m", 1.0, "Integer");
  params.addParam<Real>("W0", 1.0, "Interface thickness constant");
  params.addParam<Real>("th0", 0.0, "offset azimuthal angle");
  params.addParam<Real>("t0", 1.0, "time constant");
  return params;
}

Solidification2::Solidification2(const InputParameters & parameters)
  :Kernel(parameters),
  _Phi_var(coupled("Phi")),
  _U_var(coupled("U")),
  _Phi(coupledValue("Phi")),
  _U(coupledValue("U")),
  _PhiWdx(coupledValue("PhiWdx")),
  _PhiWdy(coupledValue("PhiWdy")),
  _PhiWdx_grad(coupledGradient("PhiWdx")),
  _PhiWdy_grad(coupledGradient("PhiWdy")),
  _Eps_m(getParam<Real>("m")),
  _m(getParam<Real>("m")),
  _W0(getParam<Real>("W0")),
  _th0(getParam<Real>("th0")),
  _t0(getParam<Real>("t0"))
{
}

Real
Solidification2::computeQpResidual()
{
  Real DimLessFD1 = 0.0;
  Real Lamda = 15.9566;
  DimLessFD1 += (((-1) * 15.9566 * _U[_qp] * std::pow(_Phi[_qp], 4.0)) + (2 * 15.9566 * _U[_qp] * std::pow(_Phi[_qp], 2.0)) + (_Phi[_qp]) + ((-1) * 15.9566 * _U[_qp])) * _test[_i][_qp] / 2;
  return DimLessFD1 / ( _t0 + 2.0 *_t0 * std::cos(_m * std::atan(_Phi_grad[_qp](1)/_Phi_grad[_qp](0)) - _th0) * _Eps_m + _t0 * _Eps_m * _Eps_m * std::cos(_m * std::atan(_Phi_grad[_qp](1)/_Phi_grad[_qp](0)) - _th0) * std::cos(_m * std::atan(_Phi_grad[_qp](1)/_Phi_grad[_qp](0)) - _th0)  );
}
