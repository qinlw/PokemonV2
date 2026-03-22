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
#include <QMetaObject>
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

	// finished 在「即将结束的工作线程」上发出，不能直接在此创建 QWidget；投递到 GUI 线程。
	QObject::connect(resourceThread, &QThread::finished, [] {
		QMetaObject::invokeMethod(
			qApp,
			[] {
				auto mainWindow = new QMainWindow();
				auto* sceneContainer = new QStackedWidget(mainWindow);
				mainWindow->setCentralWidget(sceneContainer);
				mainWindow->resize(SceneBase::sceneWidth, SceneBase::sceneHeight);

				registerSceneAll();

				SceneManager& sceneMgr = SceneManager::instance(sceneContainer);

				sceneMgr.switchScene(SceneMenu::sceneName);

				mainWindow->show();
			},
			Qt::QueuedConnection);
	});

	QObject::connect(resourceThread, &QThread::finished, resourceThread, &QObject::deleteLater);
	resourceThread->start();

	return app.exec();
}
