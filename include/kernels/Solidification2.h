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

const VariableValue & _Phi;
const VariableGradient & _Phi_grad;
const VariableValue & _U;
const Real _Eps_m;
const Real _m;
const Real _W0;
const Real _th0;
const Real _tau0;
const Real _offset;
};
#endif //SOLIDIFICATION2_H
