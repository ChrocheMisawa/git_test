//* This file is part of the MOOSE framework
//* https://www.mooseframework.org
//*
//* All rights reserved, see COPYRIGHT for full restrictions
//* https://github.com/idaholab/moose/blob/master/COPYRIGHT
//*
//* Licensed under LGPL 2.1, please see LICENSE for details
//* https://www.gnu.org/licenses/lgpl-2.1.html
#include "git_testTestApp.h"
#include "git_testApp.h"
#include "Moose.h"
#include "AppFactory.h"
#include "MooseSyntax.h"
#include "ModulesApp.h"

template <>
InputParameters
validParams<git_testTestApp>()
{
  InputParameters params = validParams<git_testApp>();
  return params;
}

git_testTestApp::git_testTestApp(InputParameters parameters) : MooseApp(parameters)
{
  git_testTestApp::registerAll(
      _factory, _action_factory, _syntax, getParam<bool>("allow_test_objects"));
}

git_testTestApp::~git_testTestApp() {}

void
git_testTestApp::registerAll(Factory & f, ActionFactory & af, Syntax & s, bool use_test_objs)
{
  git_testApp::registerAll(f, af, s);
  if (use_test_objs)
  {
    Registry::registerObjectsTo(f, {"git_testTestApp"});
    Registry::registerActionsTo(af, {"git_testTestApp"});
  }
}

void
git_testTestApp::registerApps()
{
  registerApp(git_testApp);
  registerApp(git_testTestApp);
}

/***************************************************************************************************
 *********************** Dynamic Library Entry Points - DO NOT MODIFY ******************************
 **************************************************************************************************/
// External entry point for dynamic application loading
extern "C" void
git_testTestApp__registerAll(Factory & f, ActionFactory & af, Syntax & s)
{
  git_testTestApp::registerAll(f, af, s);
}
extern "C" void
git_testTestApp__registerApps()
{
  git_testTestApp::registerApps();
}
