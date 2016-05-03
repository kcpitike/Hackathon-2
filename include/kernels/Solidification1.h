#ifndef SOLIDIFICATION1_H
#define SOLIDIFICATION1_H

#include "Kernel.h"

class Solidification1;

template<>
InputParameters validParams<Solidification1>();

class Solidification1: public Kernel
{
public:

 Solidification1(const InputParameters & parameters);

protected:
  virtual Real computeQpResidual();
  virtual Real computeQpJacobian();

private:
  const Real _D;

};


#endif /* SOLIDIFICATION1_H */
