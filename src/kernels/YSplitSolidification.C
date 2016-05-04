/**
 * @file   YSplitSolidification.C
 */

#include "YSplitSolidification.h"

class YSplitSolidification;

template<>
InputParameters validParams<YSplitSolidification>()
{
  InputParameters params = validParams<Kernel>();
  params.addRequiredCoupledVar("PhiWdy", "split phase 2 of material");
  params.addRequiredCoupledVar("Phi", "phase of material");
  params.addParam<Real>("Eps_m", 1.0, "Epsilon_m");
  params.addParam<Real>("m", 1.0, "Integer");
  params.addParam<Real>("W0", 1.0, "Interface thickness constant");
  params.addParam<Real>("th0", 0.0, "offset azimuthal angle");
  params.addParam<Real>("offset", 0.000001, "offset ");
  return params;
}

YSplitSolidification::YSplitSolidification(const InputParameters & parameters)
  :Kernel(parameters),
  _PhiWdy(coupledValue("PhiWdy")),
  _Phi(coupledValue("Phi")),
  _Phi_grad(coupledGradient("Phi")),
  _Eps_m(getParam<Real>("m")),
  _m(getParam<Real>("m")),
  _W0(getParam<Real>("W0")),
  _th0(getParam<Real>("th0")),
  _offset(getParam<Real>("offset"))
{
}

Real
YSplitSolidification::computeQpResidual()
{
  return - _test[_i][_qp] * (_Phi_grad[_qp] * _Phi_grad[_qp] * _Phi_grad[_qp](1) * _m * _W0 * _W0 * std::sin(_th0 - _m * std::atan(_Phi_grad[_qp](1)/(_Phi_grad[_qp](0)+_offset)  )) * _Eps_m * (1+ std::cos(_th0 - _m * std::atan(_Phi_grad[_qp](1)/(_Phi_grad[_qp](0)+_offset)  )) * _Eps_m) + _PhiWdy[_qp]);
}
