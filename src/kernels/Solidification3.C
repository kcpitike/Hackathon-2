/**
 * @file   Solidification3.C
 */

#include "Solidification3.h"

class Solidification3;

template<>
InputParameters validParams<Solidification3>()
{
  InputParameters params = validParams<Kernel>();
  params.addRequiredCoupledVar("Phi", "phase of material");
  params.addParam<Real>("Eps_m", 1.0, "Epsilon_m");
  params.addParam<Real>("m", 1.0, "Integer");
  params.addParam<Real>("W0", 1.0, "Interface thickness constant");
  params.addParam<Real>("th0", 0.0, "offset azimuthal angle");
  params.addParam<Real>("tau0", 1.0, "time constants");
  return params;
}

Solidification3::Solidification3(const InputParameters & parameters)
  :Kernel(parameters),
  _Phi(coupledValue("Phi")),
  _Phi_grad(coupledGradient("Phi")),
  _Eps_m(getParam<Real>("m")),
  _m(getParam<Real>("m")),
  _W0(getParam<Real>("W0")),
  _th0(getParam<Real>("th0")),
  _tau0(getParam<Real>("tau0"))
{
}

Real
Solidification3::computeQpResidual()
{
  return - 0.5 * _grad_test[_i][_qp] *_W0 * _W0 * _Phi_grad[_qp] * (1 + _Eps_m * std::cos(_th0 - _m * std::atan(_Phi_grad[_qp](1)/_Phi_grad[_qp](0))  )) * (1 + _Eps_m * std::cos(_th0 - _m * std::atan(_Phi_grad[_qp](1)/_Phi_grad[_qp](0))  )) ;
}

// Real
// Solidification3::computeQpJacobian()
// {
//   return - _grad_test[_i][_qp] *_W0 * _W0 * _grad_phi[_j][_qp] * std::pow(1 + std:cos(_th0 - _m * std::atan(_Phi_grad[_qp](1)/_Phi_grad[_qp](0))  ), 2.0) - _grad_test[_i][_qp] *_W0 * _W0 * _Phi_grad[_qp] * ;
// }
