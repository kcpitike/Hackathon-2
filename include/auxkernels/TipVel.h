#ifndef TIPVEL_H
#define TIPVEL_H

#include "AuxKernel.h"


//Forward Declarations
class TipVel;

template<>
InputParameters validParams<TipVel>();

class TipVel : public AuxKernel
{
public:
  TipVel(const InputParameters & parameters);

protected:
  virtual Real computeValue();

private:
  const VariableValue & _U;
  const VariableValue & _Phi;
  const Real _D;
};

#endif // TIPVEL_H
