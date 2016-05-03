/**
 * @file   XSplitSolidification.C
 */

#ifndef XSPLITSOLIDIFICATION_H
#define XSPLITSOLIDIFICATION_H

#include "Kernel.h"

//Forward Declarations
class XSplitSolidification;

template<>
InputParameters validParams<XSplitSolidification>();

class XSplitSolidification: public Kernel
{
public:

  XSplitSolidification(const InputParameters & parameters);

protected:
  virtual Real computeQpResidual();

  //virtual Real computeQpJacobian();

private:
  const VariableValue & _PhiWdx;
  const VariableValue & _Phi;
  const VariableGradient & _Phi_grad;
  const Real _Eps_m;
  const Real _m;
  const Real _W0;
  const Real _th0;

};
#endif //SOLIDIFICATION4X_H
