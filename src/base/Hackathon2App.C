#include "Hackathon2App.h"
#include "Moose.h"
#include "AppFactory.h"
//#include "ModulesApp.h"
#include "MooseSyntax.h"

//Specific Modules
#include "TensorMechanicsApp.h"
#include "PhaseFieldApp.h"

//AuxKernels

#include "TempField.h"

//Kernels
#include "Solidification1.h"
#include "Solidification2.h"
#include "Solidification3.h"
#include "Solidification4dxdy.h"
#include "XSplitSolidification.h"
#include "YSplitSolidification.h"
#include "DoubleWell.h" 
#include "ElasticEnergy.h"
#include "PhaseGrad.h"



template<>
InputParameters validParams<Hackathon2App>()
{
  InputParameters params = validParams<MooseApp>();

  params.set<bool>("use_legacy_uo_initialization") = false;
  params.set<bool>("use_legacy_uo_aux_computation") = false;
  params.set<bool>("use_legacy_output_syntax") = false;

  return params;
}

Hackathon2App::Hackathon2App(InputParameters parameters) :
    MooseApp(parameters)
{
  Moose::registerObjects(_factory);
  //ModulesApp::registerObjects(_factory);
  Hackathon2App::registerObjects(_factory);

  Moose::associateSyntax(_syntax, _action_factory);
  //ModulesApp::associateSyntax(_syntax, _action_factory);
  Hackathon2App::associateSyntax(_syntax, _action_factory);

  TensorMechanicsApp::registerObjects(_factory);
  TensorMechanicsApp::associateSyntax(_syntax, _action_factory);

  PhaseFieldApp::registerObjects(_factory);
  PhaseFieldApp::associateSyntax(_syntax, _action_factory);

}

Hackathon2App::~Hackathon2App()
{
}

// External entry point for dynamic application loading
extern "C" void Hackathon2App__registerApps() { Hackathon2App::registerApps(); }
void
Hackathon2App::registerApps()
{
  registerApp(Hackathon2App);
}

// External entry point for dynamic object registration
extern "C" void Hackathon2App__registerObjects(Factory & factory) { Hackathon2App::registerObjects(factory); }
void
Hackathon2App::registerObjects(Factory & factory)
{
  #undef registerObject
  #define registerObject(name) factory.reg<name>(stringifyName(name))

  registerAuxKernel(TempField);

  registerKernel(Solidification1);
  registerKernel(Solidification2);
  registerKernel(Solidification3);
  registerKernel(Solidification4dxdy);
  registerKernel(XSplitSolidification);
  registerKernel(YSplitSolidification);
  registerKernel(DoubleWell);
  registerKernel(ElasticEnergy);
  registerKernel(PhaseGrad);
  
}

// External entry point for dynamic syntax association
extern "C" void Hackathon2App__associateSyntax(Syntax & syntax, ActionFactory & action_factory) { Hackathon2App::associateSyntax(syntax, action_factory); }
void
Hackathon2App::associateSyntax(Syntax & /*syntax*/, ActionFactory & /*action_factory*/)
{
}
