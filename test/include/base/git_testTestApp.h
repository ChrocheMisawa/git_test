//* This file is part of the MOOSE framework
//* https://www.mooseframework.org
//*
//* All rights reserved, see COPYRIGHT for full restrictions
//* https://github.com/idaholab/moose/blob/master/COPYRIGHT
//*
//* Licensed under LGPL 2.1, please see LICENSE for details
//* https://www.gnu.org/licenses/lgpl-2.1.html
#ifndef GIT_TESTTESTAPP_H
#define GIT_TESTTESTAPP_H

#include "MooseApp.h"

class git_testTestApp;

template <>
InputParameters validParams<git_testTestApp>();

class git_testTestApp : public MooseApp
{
public:
  git_testTestApp(InputParameters parameters);
  virtual ~git_testTestApp();

  static void registerApps();
  static void registerAll(Factory & f, ActionFactory & af, Syntax & s, bool use_test_objs = false);
};

#endif /* GIT_TESTTESTAPP_H */
