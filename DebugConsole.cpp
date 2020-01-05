#include "DebugConsole.h"

#include <strsafe.h>
#include <tchar.h>
#include <windows.h>

#include <QDebug>
#include <string>

#include "CMExceptions.h"

BEGIN_CM_NAMESPACE

struct DebugConsoleImpl {
    HANDLE g_hChildStd_IN_Rd = nullptr;
    HANDLE g_hChildStd_IN_Wr = nullptr;
    HANDLE g_hChildStd_OUT_Rd = nullptr;
    HANDLE g_hChildStd_OUT_Wr = nullptr;
    HANDLE jobObject = nullptr;
    bool jobObjectOK = false;
    DebugConsoleImpl(const QString& exeName);
    void CreateChildProcess(const QString& exeName);
    void writeLine(const QString& str);
    void write(const QString& str);
    void ErrorExit();
};

DebugConsoleImpl::DebugConsoleImpl(const QString& exeName) {
  SECURITY_ATTRIBUTES saAttr;
  // Set the bInheritHandle flag so pipe handles are inherited.
  saAttr.nLength = sizeof(SECURITY_ATTRIBUTES);
  saAttr.bInheritHandle = TRUE;
  saAttr.lpSecurityDescriptor = nullptr;
  // Create a pipe for the child process's STDIN.
  if (!CreatePipe(&g_hChildStd_IN_Rd, &g_hChildStd_IN_Wr, &saAttr, 0))
    ErrorExit();
  // Ensure the write handle to the pipe for STDIN is not inherited.
  if (!SetHandleInformation(g_hChildStd_IN_Wr, HANDLE_FLAG_INHERIT, 0))
    ErrorExit();
  //创建一个job内核对象
  jobObject = CreateJobObjectA(nullptr, "HelloWrold");
  if (jobObject) {
    //设置job内核对象限制条件为：当job对象关闭的时候，关闭其所有子进程
    JOBOBJECT_EXTENDED_LIMIT_INFORMATION extLimitInfo;
    extLimitInfo.BasicLimitInformation.LimitFlags =
        JOB_OBJECT_LIMIT_KILL_ON_JOB_CLOSE;
    jobObjectOK =
        SetInformationJobObject(jobObject, JobObjectExtendedLimitInformation,
                                &extLimitInfo, sizeof(extLimitInfo));
  }
  // Create the child process.
  CreateChildProcess(exeName);
}

void DebugConsoleImpl::CreateChildProcess(const QString& exeName)
// Create a child process that uses the previously created pipes for STDIN and
// STDOUT.
{
  TCHAR szCmdline[200];
  exeName.toWCharArray(szCmdline);
  szCmdline[ exeName.length() ] = '\0';
  //这是子进程可执行文件的路径
  PROCESS_INFORMATION piProcInfo;
  STARTUPINFO siStartInfo;
  BOOL bSuccess = FALSE;

  // Set up members of the PROCESS_INFORMATION structure.

  ZeroMemory(&piProcInfo, sizeof(PROCESS_INFORMATION));

  // Set up members of the STARTUPINFO structure.
  // This structure specifies the STDIN and STDOUT handles for redirection.

  ZeroMemory(&siStartInfo, sizeof(STARTUPINFO));
  siStartInfo.cb = sizeof(STARTUPINFO);
  //siStartInfo.hStdError = g_hChildStd_OUT_Wr;
  siStartInfo.hStdInput = g_hChildStd_IN_Rd;
  siStartInfo.dwFlags |= STARTF_USESTDHANDLES;

  // Create the child process.

  bSuccess = CreateProcess(nullptr,
                           szCmdline,  // command line
                           nullptr,    // process security attributes
                           nullptr,    // primary thread security attributes
                           TRUE,       // handles are inherited
                           CREATE_NEW_CONSOLE,  // creation flags
                           nullptr,             // use parent's environment
                           nullptr,       // use parent's current directory
                           &siStartInfo,  // STARTUPINFO pointer
                           &piProcInfo);  // receives PROCESS_INFORMATION

  // If an error occurs, exit the application.
  if (!bSuccess)
    ErrorExit();
  else {
    // Close handles to the child process and its primary thread.
    // Some applications might keep these handles to monitor the status
    // of the child process, for example.
    if (jobObjectOK) {
      //将进程加入到job容器中去。
      if (piProcInfo.hProcess) {
        jobObjectOK = AssignProcessToJobObject(jobObject, piProcInfo.hProcess);
      }
    }
  }
  CloseHandle(piProcInfo.hProcess);
  CloseHandle(piProcInfo.hThread);
}

void DebugConsoleImpl::writeLine(const QString& str) {
  DWORD dwRead, dwWritten;
  BOOL bSuccess = FALSE;
  QByteArray array = str.toLocal8Bit();
  bSuccess = WriteFile(g_hChildStd_IN_Wr, array.constData(), array.length(),
                       &dwWritten, nullptr);
  if (!bSuccess) {
    ErrorExit();
  }

}

void DebugConsoleImpl::ErrorExit() {
  DWORD dw = GetLastError();
  Log(strerror(dw));
  exit(1);
}

DebugConsole::DebugConsole(const QString& exeName):
    debugConsole(new DebugConsoleImpl(exeName))
{

}

DebugConsole::~DebugConsole() {
    delete debugConsole;
}

void DebugConsole::writeLine(const QString& str) {
    debugConsole->writeLine(str);
}

END_CM_NAMESPACE



// Matrix3f getTrans(const Vector2i& screnn, const Vector2i& camera) {
//  Matrix3f trans;
//  trans <<
//      screnn[0] /camera[0]/2.f, 0, screnn[0] / 2.f,
//      0, -screnn[1] /camera[1] / 2.f,screnn[1] / 2.f,
//      0, 0, 1;
//  return trans;
//}