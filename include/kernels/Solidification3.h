/**
 * @file   Solidification3.C
 */

#ifndef SOLIDIFICATION3_H
#define SOLIDIFICATION3_H

#include "Kernel.h"

//Forward Declarations
class Solidification3;

template<>
InputParameters validParams<Solidification3>();

class Solidification3: public Kernel
{
public:

  Solidification3(const InputParameters & parameters);

protected:
  virtual Real computeQpResidual();

  //virtual Real computeQpJacobian();

private:
  const VariableValue & _Phi;
  const VariableGradient & _Phi_grad;
  const Real _Eps_m;
  const Real _m;
  const Real _W0;
  const Real _th0;
  const Real _Eps_m;
  const Real _m;
  const Real _W0;
  const Real _th0;
  const Real _t0;

};
#endif //SOLIDIFICATION3_H
