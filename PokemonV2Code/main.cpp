#include "UI/Scene/sceneMenu.h"
#include "UI/Scene/sceneSelector.h"
#include "Core/SceneManager/sceneManager.h"
#include "util.h"
#include <QApplication>
#include <QMainWindow>
#include <QStackedWidget>
#include <QThread>


static void loadResource()
{
	qDebug() << "Resource thread ID: " << QThread::currentThread();
	Picture* globalPicture = Picture::getInstance();
	ResourceStringName* globalString = ResourceStringName::getInstance();
	qDebug() << "resource load finished";
}

void registerSceneAll()
{
    REGISTER_SCENE(SceneMenu);
    REGISTER_SCENE(SceneSelector);
}

int main(int argc, char* argv[])
{
    QApplication app(argc, argv);
	qDebug() << "UI thread ID: " << QThread::currentThread();

	// 安装自定义日志处理器（关键！必须调用）
	qInstallMessageHandler(Util::customMessageHandler);

	// 资源子线程
	std::thread resThread(loadResource);
	resThread.detach();

    // 创建主窗口和场景容器
    QMainWindow mainWindow;
    QStackedWidget* sceneContainer = new QStackedWidget(&mainWindow);
    mainWindow.setCentralWidget(sceneContainer);
    mainWindow.resize(SceneBase::sceneWidth, SceneBase::sceneHeight);
    // 注册场景
    registerSceneAll();  
    // 初始化场景管理器
    SceneManager& sceneMgr = SceneManager::instance(sceneContainer);
    // 切换到第一场景
    sceneMgr.switchScene(SceneMenu::sceneName);

    mainWindow.show();

    return app.exec();
}
