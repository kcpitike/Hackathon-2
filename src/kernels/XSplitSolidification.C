/**
 * @file   XSplitSolidification.C
 */

#include "XSplitSolidification.h"

class XSplitSolidification;

template<>
InputParameters validParams<XSplitSolidification>()
{
  InputParameters params = validParams<Kernel>();
  params.addRequiredCoupledVar("PhiWdx", "split phase 1 of material");
  params.addRequiredCoupledVar("Phi", "phase of material");
  params.addParam<Real>("Eps_m", 1.0, "Epsilon_m");
  params.addParam<Real>("m", 1.0, "Integer");
  params.addParam<Real>("W0", 1.0, "Interface thickness constant");
  params.addParam<Real>("th0", 0.0, "offset azimuthal angle");
  return params;
}

XSplitSolidification::XSplitSolidification(const InputParameters & parameters)
  :Kernel(parameters),
  _PhiWdx(coupledValue("PhiWdx")),
  _Phi(coupledValue("Phi")),
  _Phi_grad(coupledGradient("Phi")),
  _Eps_m(getParam<Real>("Eps_m")),
  _m(getParam<Real>("m")),
  _W0(getParam<Real>("W0")),
  _th0(getParam<Real>("th0"))
{
}

Real
XSplitSolidification::computeQpResidual()
{
  return _test[_i][_qp] * (_Phi_grad[_qp] * _Phi_grad[_qp] * _Phi_grad[_qp](0) * _m * _W0 * _W0 * std::sin(_th0 - _m * std::atan(_Phi_grad[_qp](1) / _Phi_grad[_qp](0) )) * _Eps_m * (1+ std::cos(_th0 - _m * std::atan(_Phi_grad[_qp](1) / _Phi_grad[_qp](0) )) * _Eps_m)/ (_Phi_grad[_qp](0) * _Phi_grad[_qp](0) + _Phi_grad[_qp](1) * _Phi_grad[_qp](1) ) - _PhiWdx[_qp]);
}
