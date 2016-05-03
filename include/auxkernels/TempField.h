#ifndef TEMPFIELD_H
#define TEMPFIELD_H

#include "AuxKernel.h"


//Forward Declarations
class TempField;

template<>
InputParameters validParams<TempField>();

class TempField : public AuxKernel
{
public:
  TempField(const InputParameters & parameters);

protected:
  virtual Real computeValue();

private:
  const VariableValue & _U;
  const Real _Tm;
  const Real _Cp;
  const Real _L;  
};

#endif // BULKENERGYDENSITY_H
