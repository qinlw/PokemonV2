#include "Scene/sceneMenu.h"
#include "SceneManager/sceneManager.h"

#include <qapplication.h>
#include <qmainwindow.h>
#include <qstackedwidget.h>


int main(int argc, char* argv[])
{
    QApplication app(argc, argv);

    // 创建主窗口和场景容器
    QMainWindow mainWindow;
    QStackedWidget* sceneContainer = new QStackedWidget(&mainWindow);
    mainWindow.setCentralWidget(sceneContainer);
    mainWindow.resize(SceneBase::sceneWidth, SceneBase::sceneHeight);
    // 注册场景
    REGISTER_SCENE(SceneMenu);
    // 初始化场景管理器
    SceneManager& sceneMgr = SceneManager::instance(sceneContainer);
    // 切换到第一场景
    sceneMgr.switchScene("MenuScene");

    mainWindow.show();

    return app.exec();
}
