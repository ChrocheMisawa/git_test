#include "git_testApp.h"
#include "Moose.h"
#include "AppFactory.h"
#include "ModulesApp.h"
#include "MooseSyntax.h"

template <>
InputParameters
validParams<git_testApp>()
{
  InputParameters params = validParams<MooseApp>();
  return params;
}

git_testApp::git_testApp(InputParameters parameters) : MooseApp(parameters)
{
  git_testApp::registerAll(_factory, _action_factory, _syntax);
}

git_testApp::~git_testApp() {}

void
git_testApp::registerAll(Factory & f, ActionFactory & af, Syntax & s)
{
  ModulesApp::registerAll(f, af, s);
  Registry::registerObjectsTo(f, {"git_testApp"});
  Registry::registerActionsTo(af, {"git_testApp"});

  /* register custom execute flags, action syntax, etc. here */
}

void
git_testApp::registerApps()
{
  registerApp(git_testApp);
}

/***************************************************************************************************
 *********************** Dynamic Library Entry Points - DO NOT MODIFY ******************************
 **************************************************************************************************/
extern "C" void
git_testApp__registerAll(Factory & f, ActionFactory & af, Syntax & s)
{
  git_testApp::registerAll(f, af, s);
}
extern "C" void
git_testApp__registerApps()
{
  git_testApp::registerApps();
}
