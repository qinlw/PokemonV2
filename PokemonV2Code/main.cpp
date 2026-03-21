#include "Core/PlayPokemon/playPokemon.h"
#include "Core/SceneManager/sceneManager.h"
#include "UI/Scene/sceneMenu.h"
#include "UI/Scene/sceneSelector.h"
#include "util.h"
#include "Resource/picture.h"
#include "Resource/resourceStringName.h"
#include <QApplication>
#include <QDebug>
#include <QMainWindow>
#include <QStackedWidget>
#include <QThread>
#include <QObject>

void registerSceneAll()
{
    REGISTER_SCENE(SceneMenu);
    REGISTER_SCENE(SceneSelector);
}

int main(int argc, char* argv[])
{
    QApplication app(argc, argv);
	qDebug() << "UI thread ID: " << QThread::currentThread();

	// 安装自定义日志处理器
	qInstallMessageHandler(Util::customMessageHandler);

	// 资源子线程：只做 QImage 加载（不要在子线程创建/使用 QPixmap）。
	QThread* resourceThread = QThread::create([] {
		qDebug() << "Resource thread ID: " << QThread::currentThread();
		Picture* globalPicture = Picture::getInstance();
		(void)globalPicture;
		ResourceStringName* globalString = ResourceStringName::getInstance();
		(void)globalString;
		qDebug() << "resource load finished";
	});

	QObject::connect(resourceThread, &QThread::finished, [] {
		// 创建主窗口和场景容器（必须在 GUI 线程，且资源已就绪）
		auto mainWindow = new QMainWindow();
		auto* sceneContainer = new QStackedWidget(mainWindow);
		mainWindow->setCentralWidget(sceneContainer);
		mainWindow->resize(SceneBase::sceneWidth, SceneBase::sceneHeight);

		// 注册场景
		registerSceneAll();

		// 初始化场景管理器
		SceneManager& sceneMgr = SceneManager::instance(sceneContainer);

		// 切换到第一场景
		sceneMgr.switchScene(SceneMenu::sceneName);

		mainWindow->show();
	});

	QObject::connect(resourceThread, &QThread::finished, resourceThread, &QObject::deleteLater);
	resourceThread->start();

	return app.exec();
}
