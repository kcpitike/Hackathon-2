/**
 * @file   Solidification4dxdy.C
 */

 #include "Solidification4dxdy.h"

class Solidification4dxdy;

template<>
InputParameters validParams<Solidification4dxdy>()
{
  InputParameters params = validParams<Kernel>();
  params.addRequiredCoupledVar("Phi", "The phase field parameter");
  params.addRequiredCoupledVar("PhiWdx", "split phase 1 of material");
  params.addRequiredCoupledVar("PhiWdy", "split phase 2 of material");
  params.addParam<Real>("Eps_m", 1.0, "Epsilon_m");
  params.addParam<Real>("m", 1.0, "Integer");
  params.addParam<Real>("W0", 1.0, "Interface thickness constant");
  params.addParam<Real>("th0", 0.0, "offset azimuthal angle");
  params.addParam<Real>("tau0", 1.0, "time constant");
  params.addParam<Real>("offset", 0.00001, "offset");
  return params;
}

Solidification4dxdy::Solidification4dxdy(const InputParameters & parameters)
  :Kernel(parameters),
  _Phi_grad(coupledGradient("Phi")),
  _PhiWdx(coupledValue("PhiWdx")),
  _PhiWdy(coupledValue("PhiWdy")),
  _PhiWdx_grad(coupledGradient("PhiWdx")),
  _PhiWdy_grad(coupledGradient("PhiWdy")),
  _Eps_m(getParam<Real>("m")),
  _m(getParam<Real>("m")),
  _W0(getParam<Real>("W0")),
  _th0(getParam<Real>("th0")),
  _tau0(getParam<Real>("tau0")),
  _offset(getParam<Real>("offset"))
{
}

Real
Solidification4dxdy::computeQpResidual()
{
  Real q = 1.0;
  return 0.5 * _test[_i][_qp] * (_PhiWdx_grad[_qp](0)  +  _PhiWdy_grad[_qp](1) ) / ( _tau0 + 2.0 *_tau0 * std::cos(_m * q  - _th0) * _Eps_m + _tau0 * std::pow(_Eps_m, 2.0) * std::cos(_m * q - _th0) * std::cos(_m * q - _th0)  ) ;
}

// Real
// Solidification3::computeQpJacobian()
// {
//   return - _grad_test[_i][_qp] *_W0 * _W0 * _grad_phi[_j][_qp] * std::pow(1 + std:cos(_th0 - _m * std::atan(_Phi_grad[_qp](1)/_Phi_grad[_qp](0))  ), 2.0) - _grad_test[_i][_qp] *_W0 * _W0 * _Phi_grad[_qp] * ;
// }
