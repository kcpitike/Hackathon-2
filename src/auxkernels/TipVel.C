#include "TipVel.h"

template<>
InputParameters validParams<TipVel>()
{
  InputParameters params = validParams<AuxKernel>();
  params.addRequiredCoupledVar("D", "The Diffusion Coefficient");
  return params;
}

TipVel::TipVel(const InputParameters & parameters) :
  AuxKernel(parameters),
  _U(coupledValue("U")),
  _Phi(coupledValue("Phi")),
  _D(getParam<Real>("D"))
{}

Real
TipVel::computeValue()
{
  return _D * (_grad_Phi[_qp]/(std::abs(_grad_Phi[_qp]))) * (_grad_U[_qp]);
}