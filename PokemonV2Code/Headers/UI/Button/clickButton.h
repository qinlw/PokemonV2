#pragma once

#include <QTimer>
#include <QMouseEvent>
#include "UI/Button/buttonBase.h"


class ClickButton : public ButtonBase
{
	Q_OBJECT
protected:
	bool isPressed;
	int pressOffset;
	std::pair<int, int> pressSleep;
	std::function<void()> buttonEventFun;


public:
	explicit ClickButton(QWidget* parent = nullptr);
	void setPressOffsetAndPressSleep(int offset, std::pair<int, int> sleep);
	void setButtonEventFun(std::function<void()>&& eventFun);

protected:
	void mousePressEvent(QMouseEvent* event) override;
	void mouseReleaseEvent(QMouseEvent* event) override;
	void mouseMoveEvent(QMouseEvent* event) override;

private:
	void buttonSink();
	void buttonBulge();
	void buttonEvent();

};