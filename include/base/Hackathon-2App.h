#ifndef HACKATHON-2APP_H
#define HACKATHON-2APP_H

#include "MooseApp.h"

class Hackathon-2App;

template<>
InputParameters validParams<Hackathon-2App>();

class Hackathon-2App : public MooseApp
{
public:
  Hackathon-2App(InputParameters parameters);
  virtual ~Hackathon-2App();

  static void registerApps();
  static void registerObjects(Factory & factory);
  static void associateSyntax(Syntax & syntax, ActionFactory & action_factory);
};

#endif /* HACKATHON-2APP_H */
