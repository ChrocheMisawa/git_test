//* This file is part of the MOOSE framework
//* https://www.mooseframework.org
//*
//* All rights reserved, see COPYRIGHT for full restrictions
//* https://github.com/idaholab/moose/blob/master/COPYRIGHT
//*
//* Licensed under LGPL 2.1, please see LICENSE for details
//* https://www.gnu.org/licenses/lgpl-2.1.html
#ifndef GIT_TESTAPP_H
#define GIT_TESTAPP_H

#include "MooseApp.h"

class git_testApp;

template <>
InputParameters validParams<git_testApp>();

class git_testApp : public MooseApp
{
public:
  git_testApp(InputParameters parameters);
  virtual ~git_testApp();

  static void registerApps();
  static void registerAll(Factory & f, ActionFactory & af, Syntax & s);
};

#endif /* GIT_TESTAPP_H */
