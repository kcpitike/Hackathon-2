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
};
#endif //SOLIDIFICATION2_H
