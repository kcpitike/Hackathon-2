#ifndef HACKATHON2APP_H
#define HACKATHON2APP_H

#include "MooseApp.h"

class Hackathon2App;

template<>
InputParameters validParams<Hackathon2App>();

class Hackathon2App : public MooseApp
{
public:
  Hackathon2App(InputParameters parameters);
  virtual ~Hackathon2App();

  static void registerApps();
  static void registerObjects(Factory & factory);
  static void associateSyntax(Syntax & syntax, ActionFactory & action_factory);
};

#endif /* HACKATHON2APP_H */
