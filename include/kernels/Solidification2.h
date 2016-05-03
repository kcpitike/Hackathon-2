#ifndef SOLIDIFICATION2_H
#define SOLIDIFICATION2_H

#include "Kernel.h"

class Solidification2;

template<>
InputParameters validParams<Solidification2>();

class Solidification2: public Kernel
{
public:
  Solidification2(const InputParameters & parameters);

protected:
  virtual Real computeQpResidual();

private:
const unsigned int _Phi_var;
const unsigned int _U_var;
const VariableValue & _Phi;
const VariableValue & _U;
const VariableValue & _PhiWdx;
const VariableValue & _PhiWdy;
const VariableGradient & _PhiWdx_grad;
const VariableGradient & _PhiWdy_grad;
const Real _Eps_m;
const Real _m;
const Real _W0;
const Real _th0;
const Real _t0;
};
#endif //SOLIDIFICATION2_H
