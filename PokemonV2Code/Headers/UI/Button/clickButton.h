#pragma once

#include <qtimer.h>
#include "Button/buttonBase.h"


class ClickButton : public ButtonBase
{
	Q_OBJECT
protected:
	int pressOffset;
	std::pair<int, int> pressSleep;


public:
	explicit ClickButton(QWidget* parent = nullptr);
	void setPressOffsetAndPressSleep(int offset, std::pair<int, int> sleep);

private:
	void buttonSink();
	void buttonBulge();
	void buttonEvent();

};