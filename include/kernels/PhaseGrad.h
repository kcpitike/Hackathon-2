#ifndef PHASEGRAD_H
#define PHASEGRAD_H

#include "Kernel.h"

class PhaseGrad;

template<>
InputParameters validParams<PhaseGrad>();

class PhaseGrad: public Kernel
{
public:
  PhaseGrad(const InputParameters & parameters);

protected:
  virtual Real computeQpResidual();

private:

const VariableValue & _Phi;
const VariableGradient & _Phi_grad;
const Real _k;
};
#endif //PHASEGRAD_H
