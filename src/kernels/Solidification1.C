#include “Solidification1.h”


template<>
InputParameters validParams<Solidification1>()
{
  InputParameters p = validParams<Kernel>();
  params.addRequiredParam<Real>(“D”, "The Thermal Diffusion Constant”);
  return p;
}

Solidification1::Solidification1(const InputParameters & parameters) :
    Kernel(parameters),
 _D(getParam<Real>(“D”))
{
}

Solidification1::~Solidification1()
{
}

Real
Solidification1::computeQpResidual()
{
  return _D * _grad_u[_qp] * _grad_test[_i][_qp];
}

Real
Solidification1::computeQpJacobian()
{
  return _D * _grad_phi[_j][_qp] * _grad_test[_i][_qp];
}

