#include "Button/clickButton.h"


ClickButton::ClickButton(QWidget* parent) : ButtonBase(parent), pressOffset(5), pressSleep({50, 300})
{
	connect(this, &QPushButton::pressed, this, &ClickButton::buttonSink);
}

void ClickButton::setPressOffsetAndPressSleep(int offset, std::pair<int, int> sleep)
{
	pressOffset = offset;
	pressSleep = sleep;
}

void ClickButton::buttonSink()
{
	buttonPosition.second += pressOffset;
	setButtonPosition(buttonPosition);
	QTimer::singleShot(pressSleep.first, this, &ClickButton::buttonBulge);
}

void ClickButton::buttonBulge()
{
	buttonPosition.second -= pressOffset;
	setButtonPosition(buttonPosition);
	QTimer::singleShot(pressSleep.second, this, &ClickButton::buttonEvent);
}

void ClickButton::buttonEvent()
{
	std::cerr << "fff" << std::endl;
	qWarning() << "fgfgf";
}

