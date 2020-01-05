#pragma once

// using namespace Eigen;
#include<QString>
#include "CMDefines.h"
BEGIN_CM_NAMESPACE

struct DebugConsoleImpl;
class DebugConsole {
  DebugConsoleImpl* debugConsole;
public:
  DebugConsole(const QString& exeName);
  ~DebugConsole();
  void writeLine(const QString& str);
};


END_CM_NAMESPACE