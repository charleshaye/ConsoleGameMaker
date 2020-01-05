#include "CMApplication.h"

#include "InputTranslator_Win.h"
#include "PainterDevice_Win.h"
#include "SceneManager.h"
#ifdef _DEBUG
#include <QDebug>
#include <QScopedPointer>
#include <QThread>
#include <iostream>
#endif  // DEBUG

BEGIN_CM_NAMESPACE
using Translator_ptr = QScopedPointer<InputTranslator>;

static Translator_ptr inputReader;
static QThread readInputThread;

CMApplication::CMApplication(int argc, char* argv[])
    : QCoreApplication(argc, argv) {
  SceneManager::addScene(new Scene("Main Scene"));
  //#ifdef WIN32
  //	inputReader.reset(new InputTranslator_Win);
  //#endif // WIN32
  //	inputReader->moveToThread(STD addressof(readInputThread));
  //  connect(&readInputThread, &QThread::finished,
  //	  inputReader.get(), &QObject::deleteLater);
  //
  //  connect(this, &CMApplication::startRead, inputReader.get(),
  //          &InputTranslator::startLoop);

  // readInputThread.start();
}

bool CMApplication::exec() {
  /*emit startRead();*/
  return QCoreApplication::exec();
}

PainterDevice* CMApplication::getPainterDevice() {
  return new PainterDevice_Win();
}

END_CM_NAMESPACE