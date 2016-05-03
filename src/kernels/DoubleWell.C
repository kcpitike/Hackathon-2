#include "DoubleWell.h"

template<>
InputParameters validParams<DoubleWell>()
{
  InputParameters params = validParams<Kernel>();
  params.addRequiredCoupledVar("Phi", "Phase field parameter");
  params.addRequiredParam<Real>("h0", " zero ");
  return params;
}

DoubleWell::DoubleWell(const InputParameters & parameters) :
    Kernel(parameters),
  _Phi(coupledValue("Phi")),
  _h0(getParam<Real>("h0"))
{
}

Real
DoubleWell::computeQpResidual()
{
  return _h0 * ((std::pow(_Phi[_qp], 4.0)) - (2 * std::pow(_Phi[_qp], 3.0)) + (std::pow(_Phi[_qp], 2.0))) * _grad_test[_i][_qp];
}
