#include "OrchidsApp.h"
#include "Moose.h"
#include "AppFactory.h"
#include "ModulesApp.h"
#include "MooseSyntax.h"

template<>
InputParameters validParams<OrchidsApp>()
{
  InputParameters params = validParams<MooseApp>();
  return params;
}

OrchidsApp::OrchidsApp(InputParameters parameters) :
    MooseApp(parameters)
{
  Moose::registerObjects(_factory);
  ModulesApp::registerObjects(_factory);
  OrchidsApp::registerObjects(_factory);

  Moose::associateSyntax(_syntax, _action_factory);
  ModulesApp::associateSyntax(_syntax, _action_factory);
  OrchidsApp::associateSyntax(_syntax, _action_factory);
}

OrchidsApp::~OrchidsApp()
{
}

// External entry point for dynamic application loading
extern "C" void OrchidsApp__registerApps() { OrchidsApp::registerApps(); }
void
OrchidsApp::registerApps()
{
  registerApp(OrchidsApp);
}

// External entry point for dynamic object registration
extern "C" void OrchidsApp__registerObjects(Factory & factory) { OrchidsApp::registerObjects(factory); }
void
OrchidsApp::registerObjects(Factory & factory)
{
}

// External entry point for dynamic syntax association
extern "C" void OrchidsApp__associateSyntax(Syntax & syntax, ActionFactory & action_factory) { OrchidsApp::associateSyntax(syntax, action_factory); }
void
OrchidsApp::associateSyntax(Syntax & /*syntax*/, ActionFactory & /*action_factory*/)
{
}
