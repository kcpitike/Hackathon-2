/**
 * @file   Solidification4dxdy.C
 */

#ifndef SOLIDIFICATION4DXDY_H
#define SOLIDIFICATION4DXDY_H

#include "Kernel.h"

//Forward Declarations
class Solidification4dxdy;

template<>
InputParameters validParams<Solidification4dxdy>();

class Solidification4dxdy: public Kernel
{
public:

  Solidification4dxdy(const InputParameters & parameters);

protected:
  virtual Real computeQpResidual();

  //virtual Real computeQpJacobian();

private:
  const VariableValue & _PhiWdx;
  const VariableValue & _PhiWdy;
  const VariableGradient & _PhiWdx_grad;
  const VariableGradient & _PhiWdy_grad;

};
#endif //SOLIDIFICATION4X_H
