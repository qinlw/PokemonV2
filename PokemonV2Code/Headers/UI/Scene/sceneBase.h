#pragma once

#include <qwidget.h>
#include <qbuffer.h>
#include <qpushbutton.h>   
#include "Resource/picture.h"
#include "Button/clickButton.h"

#ifdef _WIN32 
#include <windows.h>  
#endif


class SceneBase : public QWidget
{
	Q_OBJECT
public:
	int sceneWidth;
	int sceneHeight;
	Picture* globalPicture;
	ResourceStringName* globalString;


public:
	explicit SceneBase(QWidget* parent = nullptr);
	~SceneBase() override;

protected:
	void showEvent(QShowEvent* event) override;
	void closeEvent(QCloseEvent* event) override;

private:
	void minimizeConsole();
	void closeConsole();

};