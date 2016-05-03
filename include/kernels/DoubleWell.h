#ifndef DOUBLEWELL_H
#define DOUBLEWELL_H

#include "Kernel.h"

class DoubleWell;

template<>
InputParameters validParams<DoubleWell>();

class DoubleWell: public Kernel
{
public:
  DoubleWell(const InputParameters & parameters);

protected:
  virtual Real computeQpResidual();

private:

const VariableValue & _Phi;
const Real _h0;
};
#endif //DOUBLEWELL_H
