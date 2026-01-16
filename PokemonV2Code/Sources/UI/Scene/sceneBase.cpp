#include "UI/Scene/sceneBase.h"


int SceneBase::sceneWidth = 1270;
int SceneBase::sceneHeight = 720;

SceneBase::SceneBase(QWidget* parent) : QWidget(parent)
{
    globalPicture = Picture::getInstance();
    globalString = ResourceStringName::getInstance();

    setAutoFillBackground(true);
    setWindowTitle("Pokemon");
    resize(sceneWidth, sceneHeight);
}

SceneBase::~SceneBase()
{
}

void SceneBase::showEvent(QShowEvent* event)
{
    QWidget::showEvent(event);
    QTimer::singleShot(50, this, &SceneBase::minimizeConsole);
}

void SceneBase::closeEvent(QCloseEvent* event)
{
    closeConsole();
}

void SceneBase::minimizeConsole()
{
#ifdef _WIN32 
    HWND consoleHwnd = GetConsoleWindow();
    if (consoleHwnd != nullptr && IsWindow(consoleHwnd))
        ShowWindow(consoleHwnd, SW_MINIMIZE);
#endif 
}

void SceneBase::closeConsole()
{
#ifdef _WIN32 
    HWND consoleHwnd = GetConsoleWindow();
    if (consoleHwnd == nullptr) return;

    DWORD consolePid = 0;
    GetWindowThreadProcessId(consoleHwnd, &consolePid);
    if (consolePid == 0) return;

    HANDLE hProcess = OpenProcess(PROCESS_TERMINATE, FALSE, consolePid);
    if (hProcess == nullptr) return;

    TerminateProcess(hProcess, 0);
    CloseHandle(hProcess); 
#endif
}