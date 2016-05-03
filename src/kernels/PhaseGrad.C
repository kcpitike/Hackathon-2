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
  _Phi(var(coupled("Phi")),
  _Phi_grad(coupledGradient("Phi")),
  _D(getParam<Real>("k")),
{
}

Real
PhaseGrad::computeQpResidual()
{
  return _k * _Phi_grad[_qp] * _Phi_grad[_qp] * _grad_test[_i][_qp] / 2;
}
