/**
 * @file   YSplitSolidification.C
 */

#ifndef YSPLITSOLIDIFICATION_H
#define YSPLITSOLIDIFICATION_H

#include "Kernel.h"

//Forward Declarations
class YSplitSolidification;

template<>
InputParameters validParams<YSplitSolidification>();

class YSplitSolidification: public Kernel
{
public:

  YSplitSolidification(const InputParameters & parameters);

protected:
  virtual Real computeQpResidual();

  //virtual Real computeQpJacobian();

private:
  const VariableValue & _PhiWdy;
  const VariableValue & _Phi;
  const VariableGradient & _Phi_grad;
  const Real _Eps_m;
  const Real _m;
  const Real _W0;
  const Real _th0;

};
#endif //SOLIDIFICATION4X_H
