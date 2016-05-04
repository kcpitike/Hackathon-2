#ifndef ELASTICENERGY_H
#define ELASTICENERGY_H

#include "Kernel.h"
#include "RankFourTensor.h"

//Forward Declarations
class ElasticEnergy;

template<>
InputParameters validParams<ElasticEnergy>();

class ElasticEnergy: public Kernel
{
public:

  ElasticEnergy(const InputParameters & parameters);

protected:
  virtual Real computeQpResidual();

  //virtual Real computeQpJacobian();

private:
  const MaterialProperty<RankFourTensor> & _elasticity_tensor;
  const VariableValue & _Phi;
  const VariableValue & _disp_x;
  const VariableValue & _disp_y;
  const VariableValue & _disp_z;
  const VariableGradient & _Phi_grad;
  const VariableGradient & _disp_x_grad;
  const VariableGradient & _disp_y_grad;
  const VariableGradient & _disp_z_grad;
};
#endif //ELASTICENERGY_H
