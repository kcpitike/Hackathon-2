#include "PhaseGrad.h"

template<>
InputParameters validParams<PhaseGrad>()
{
  InputParameters params = validParams<Kernel>();
  params.addRequiredParam<Real>("k", "Force = 3 * 10^-9 J/m");
  params.addRequiredCoupledVar("Phi", "Phase field Parameter");
  return params;
}

PhaseGrad::PhaseGrad(const InputParameters & parameters) :
    Kernel(parameters),
  _Phi(coupledValue("Phi")),
  _Phi_grad(coupledGradient("Phi")),
  _k(getParam<Real>("k"))
{
}

Real
PhaseGrad::computeQpResidual()
{
  return _k * _Phi_grad[_qp] * _grad_phi[_j][_qp] * _test[_i][_qp];
}
