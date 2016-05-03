#include "Solidification2.h"

template<>
InputParameters validParams<Solidification2>()
{
  InputParameters params = validParams<Kernel>();
  params.addRequiredCoupledVar("Phi", "The phase field parameter");
  params.addRequiredCoupledVar("U", "The dimensionless temperature field");
  return params;
}

Solidification2::Solidification2(const InputParameters & parameters)
  :Kernel(parameters),
  _Phi_var(coupled("Phi")),
  _U_var(coupled("U")),
  _Phi(coupledValue("Phi")),
  _U(coupledValue("U"))
{
}

Real
Solidification2::computeQpResidual()
{
  Real DimLessFD1 = 0.0;
  Real Lamda = 15.9566;
  DimLessFD1 += (((-1) * 15.9566 * _U[_qp] * std::pow(_Phi[_qp], 4.0)) + (2 * 15.9566 * _U[_qp] * std::pow(_Phi[_qp], 2.0)) + (_Phi[_qp]) + ((-1) * 15.9566 * _U[_qp])) * _test[_i][_qp];
  return DimLessFD1;
}
