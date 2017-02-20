#ifndef ORCHIDSAPP_H
#define ORCHIDSAPP_H

#include "MooseApp.h"

class OrchidsApp;

template<>
InputParameters validParams<OrchidsApp>();

class OrchidsApp : public MooseApp
{
public:
  OrchidsApp(InputParameters parameters);
  virtual ~OrchidsApp();

  static void registerApps();
  static void registerObjects(Factory & factory);
  static void associateSyntax(Syntax & syntax, ActionFactory & action_factory);
};

#endif /* ORCHIDSAPP_H */
