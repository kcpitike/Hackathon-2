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
  const VariableValue & _U;
};

#endif // BULKENERGYDENSITY_H
