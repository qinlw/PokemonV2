#pragma once

#include <qtimer.h>
#include <QMouseEvent>
#include "Button/buttonBase.h"


class ClickButton : public ButtonBase
{
	Q_OBJECT
protected:
	bool isPressed;
	int pressOffset;
	std::pair<int, int> pressSleep;


public:
	explicit ClickButton(QWidget* parent = nullptr);
	void setPressOffsetAndPressSleep(int offset, std::pair<int, int> sleep);

protected:
	void mousePressEvent(QMouseEvent* event) override;
	void mouseReleaseEvent(QMouseEvent* event) override;
	void mouseMoveEvent(QMouseEvent* event) override;

private:
	void buttonSink();
	void buttonBulge();
	void buttonEvent();

};