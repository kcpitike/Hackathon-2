#include "TempField.h"

template<>
InputParameters validParams<TempField>()
{
  InputParameters params = validParams<AuxKernel>();
  params.addRequiredCoupledVar("U", "The y component of the polarization");
  params.addRequiredParam<Real>("Tm", "Melting Temperature");
  params.addRequiredParam<Real>("L", "Geometry Size");
  params.addRequiredParam<Real>("Cp", "Specific Heat");
  return params;
}

TempField::TempField(const InputParameters & parameters) :
  AuxKernel(parameters),
  _U(coupledValue("U")),
  _Tm(getParam<Real>("Tm")),
  _Cp(getParam<Real>("Cp")),
  _L(getParam<Real>("L"))
{}

Real
TempField::computeValue()
{
  return _U[_qp] * _L / _Cp + _Tm;
}
