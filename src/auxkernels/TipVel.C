#include "TipVel.h"

template<>
InputParameters validParams<TipVel>()
{
  InputParameters params = validParams<AuxKernel>();
  params.addRequiredCoupledVar("Phi", "phase of material");
  params.addRequiredCoupledVar("U", "phase of material");
  params.addRequiredCoupledVar("D", "The Diffusion Coefficient");
  return params;
}

TipVel::TipVel(const InputParameters & parameters) :
  AuxKernel(parameters),
  _U(coupledValue("U")),
  _Phi(coupledValue("Phi")),
  _U_grad(coupledGradient("U")),
  _Phi_grad(coupledGradient("Phi")),
  _D(getParam<Real>("D"))
{}

Real
TipVel::computeValue()
{
  return _D * (_Phi_grad[_qp]/(std::pow(_Phi_grad[_qp](0)*_Phi_grad[_qp](0)+ _Phi_grad[_qp](1)*_Phi_grad[_qp](1),0.5)) * (_U_grad[_qp]));
}
