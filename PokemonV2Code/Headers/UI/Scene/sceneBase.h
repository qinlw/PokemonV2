#pragma once

#include <QWidget>
#include <qbuffer.h>
#include <QPushButton>  
#include <QString>
#include <qvariantmap.h>
#include "Resource/picture.h"
#include "UI/Button/clickButton.h"

#ifdef _WIN32 
#include <windows.h>  
#endif


class SceneRegistry;

#define REGISTER_SCENE(SCENE_CLASS) \
    static bool _register_##SCENE_CLASS = []() { \
        SceneRegistry::instance()->registerSceneCreator( \
            SCENE_CLASS::staticSceneName(), \
            []() -> SceneBase* { return new SCENE_CLASS(); } \
        ); \
        return true; \
    }();

class SceneBase : public QWidget	
{
	Q_OBJECT
public:
	static int sceneWidth;
	static int sceneHeight;

protected:
	Picture* globalPicture;
	ResourceStringName* globalString;


public:
	explicit SceneBase(QWidget* parent = nullptr);
	~SceneBase() override;
	virtual QString getSceneName() const = 0;
	virtual void onEnter(const QVariantMap& params = {}) {}
	virtual void onExit() {}

protected:
	void showEvent(QShowEvent* event) override;
	void closeEvent(QCloseEvent* event) override;

private:
	void minimizeConsole();
	void closeConsole();

signals:
	void requestSwitchScene(const QString& targetId, const QVariantMap& params = {});

};