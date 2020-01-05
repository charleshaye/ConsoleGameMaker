#pragma once
// Created on 2019-10-12   23: 35: 48
// Platform: Windows 10 1903
// Namespace:
// Title: No Title

#include <QtCore/QCoreApplication>
#include "CMDefines.h"

BEGIN_CM_NAMESPACE
struct PainterDevice;
class CMApplication : public QCoreApplication {
  Q_OBJECT
 public:
  CMApplication(int argc, char *argv[]);
  bool exec();
  static PainterDevice* getPainterDevice();
 private:
};

END_CM_NAMESPACE