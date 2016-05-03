#ifndef SOLIDIFICATION2_H
#define SOLIDIFICATION2_H

#include "Kernel.h"

class SOLIDIFICATION2;

template<>
InputParameters validParams<SOLIDIFICATION2>();

class SOLIDIFICATION2: public Kernel
{
public:

  SOLIDIFICATION2(const InputParameters & parameters);

protected:
  virtual Real computeQpResidual();

  const unsigned int _Phi;
  const unsigned int _U;
  const VariableValue & _Phi;
  const VariableValue & _U;

};
#endif //SOLIDIFICATION2_H
