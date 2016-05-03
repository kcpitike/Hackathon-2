#ifndef SOLIDIFICATION1_H
#define SOLIDIFICATION1_H

#include "Kernel.h"

class Solidification1;

template<>
InputParameters validParams<Solidification1>();

/**
 * This kernel implements the Laplacian operator:
 * $\nabla u \cdot \nabla \phi_i$
 */
class Solidification1 : public Kernel
{
public:
  Solidification1(const InputParameters & parameters);

  virtual ~Solidification1();

protected:
  virtual Real computeQpResidual();

  virtual Real computeQpJacobian();

  const Real _D;
};


#endif /* SOLIDIFICATION1_H */
