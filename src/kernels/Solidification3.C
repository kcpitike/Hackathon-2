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
  params.addRequiredParam<Real>("Eps_m", 1.0, "Epsilon_m");
  params.addRequiredParam<Real>("m", 1.0, "Integer");
  params.addRequiredParam<Real>("W0", 1.0, "Interface thickness constant");
  params.addRequiredParam<Real>("th0", 0.0, "offset azimuthal angle");
  return params;
}

Solidification3::Solidification3(const InputParameters & parameters)
  :Kernel(parameters),
  _Phi(coupledValue("Phi")),
  _Phi_grad(coupledGradient("Phi")),
  _Eps_m(getParam<Real>("m")),
  _m(getParam<Real>("m")),
  _W0(getParam<Real>("W0")),
  _th0(getParam<Real>("th0"))
{
}

Real
Solidification3::computeQpResidual()
{
  return - _grad_test[_i][_qp] *_W0 * _W0 * _Phi_grad[_qp] * std::pow(1 + _Eps_m * std::cos(_th0 - _m * std::atan(_Phi_grad[_qp](1)/_Phi_grad[_qp](0))  ), 2.0);
}

// Real
// Solidification3::computeQpJacobian()
// {
//   return - _grad_test[_i][_qp] *_W0 * _W0 * _grad_phi[_j][_qp] * std::pow(1 + std:cos(_th0 - _m * std::atan(_Phi_grad[_qp](1)/_Phi_grad[_qp](0))  ), 2.0) - _grad_test[_i][_qp] *_W0 * _W0 * _Phi_grad[_qp] * ;
// }
