#include "ElasticEnergy.h"
#include "ComputeElasticityTensor.h"


template<>
InputParameters validParams<ElasticEnergy>()
{
    InputParameters params = validParams<ElasticEnergy>();
    params.addRequiredCoupledVar("Phi", "phase of material");
    params.addRequiredCoupledVar("_disp_x", "X displacement");
    params.addRequiredCoupledVar("_disp_y", "Y displacement");
    params.addRequiredCoupledVar("_disp_z", "Z displacement");
  return params;
}

ElasticEnergy::ElasticEnergy(const InputParameters & parameters) :
    Kernel(parameters),
    _elasticity_tensor(getMaterialProperty<RankFourTensor>("elasticity_tensor")),
    _Phi(coupledValue("Phi")),
    _disp_x(coupledValue("_disp_x")),
    _disp_y(coupledValue("_disp_y")),
    _disp_z(coupledValue("_disp_z")),
    _Phi_grad(coupledGradient("_Phi")),
    _disp_x_grad(coupledGradient("_disp_x")),
    _disp_y_grad(coupledGradient("_disp_y")),
    _disp_z_grad(coupledGradient("_disp_z"))
{
}

Real
ElasticEnergy::computeQpResidual()
{
    Real ElEnergy = 0.0;
    //int i, j;
    for(int i = 0; i < 3; ++i )
    {
        for(int k = 0; k < 3; ++k )
        {
            ElEnergy += (_elasticity_tensor[_qp](i,0,k,0) * _disp_x_grad[_qp](i) * _disp_x_grad[_qp](k)) + (_elasticity_tensor[_qp](i,1,k,0) * _disp_y_grad[_qp](i) * _disp_x_grad[_qp](k)) + (_elasticity_tensor[_qp](i,2,k,0) * _disp_z_grad[_qp](i) * _disp_x_grad[_qp](k)) + (_elasticity_tensor[_qp](i,0,k,1) * _disp_x_grad[_qp](i) * _disp_y_grad[_qp](k)) + (_elasticity_tensor[_qp](i,1,k,1) * _disp_y_grad[_qp](i) * _disp_y_grad[_qp](k)) + (_elasticity_tensor[_qp](i,2,k,1) * _disp_z_grad[_qp](i) * _disp_y_grad[_qp](k)) + (_elasticity_tensor[_qp](i,0,k,2) * _disp_x_grad[_qp](i) * _disp_z_grad[_qp](k)) + (_elasticity_tensor[_qp](i,1,k,2) * _disp_y_grad[_qp](i) * _disp_z_grad[_qp](k)) + (_elasticity_tensor[_qp](i,2,k,2) * _disp_z_grad[_qp](i) * _disp_z_grad[_qp](k));
        }
    }
    
    return ((30 * std::pow(_Phi[_qp], 4.0)) - (60 * std::pow(_Phi[_qp], 3.0)) + (30 * std::pow(_Phi[_qp], 2.0))) * ElEnergy;
}
