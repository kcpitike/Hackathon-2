/**
 * @file   Solidification4dxdy.C
 */

 #include "Solidification4dxdy.h"

class Solidification4dxdy;

template<>
InputParameters validParams<Solidification4dxdy>()
{
  InputParameters params = validParams<Kernel>();
  params.addRequiredCoupledVar("PhiWdx", "split phase 1 of material");
  params.addRequiredCoupledVar("PhiWdy", "split phase 2 of material");
  return params;
}

Solidification4dxdy::Solidification4dxdy(const InputParameters & parameters)
  :Kernel(parameters),
  _PhiWdx(coupledValue("PhiWdx")),
  _PhiWdy(coupledValue("PhiWdy")),
  _PhiWdx_grad(coupledGradient("PhiWdx")),
  _PhiWdy_grad(coupledGradient("PhiWdy"))
{
}

Real
Solidification4dxdy::computeQpResidual()
{
  return 0.5 * _test[_i][_qp] * (_PhiWdx_grad[_qp](0)  +  _PhiWdy_grad[_qp](1) ) ;
}

// Real
// Solidification3::computeQpJacobian()
// {
//   return - _grad_test[_i][_qp] *_W0 * _W0 * _grad_phi[_j][_qp] * std::pow(1 + std:cos(_th0 - _m * std::atan(_Phi_grad[_qp](1)/_Phi_grad[_qp](0))  ), 2.0) - _grad_test[_i][_qp] *_W0 * _W0 * _Phi_grad[_qp] * ;
// }
