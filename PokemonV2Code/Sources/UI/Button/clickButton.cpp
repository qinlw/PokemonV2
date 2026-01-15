#include "UI/Button/clickButton.h"


ClickButton::ClickButton(QWidget* parent) : ButtonBase(parent), isPressed(false), pressOffset(5), pressSleep({50, 300})
{
}

void ClickButton::setPressOffsetAndPressSleep(int offset, std::pair<int, int> sleep)
{
	pressOffset = offset;
	pressSleep = sleep;
}

void ClickButton::mousePressEvent(QMouseEvent* event)
{
	isPressed = true;
	buttonSink();
	event->accept();
}

void ClickButton::mouseReleaseEvent(QMouseEvent* event)
{
	isPressed = false;
	buttonBulge();
	event->accept();
}

void ClickButton::mouseMoveEvent(QMouseEvent* event)
{
	event->accept();
}

void ClickButton::buttonSink()
{
	buttonPosition.second += pressOffset;
	setButtonPosition(buttonPosition);
	QTimer::singleShot(pressSleep.first, this, []{});
}

void ClickButton::buttonBulge()
{
	buttonPosition.second -= pressOffset;
	setButtonPosition(buttonPosition);
	QTimer::singleShot(pressSleep.second, this, &ClickButton::buttonEvent);
}

void ClickButton::buttonEvent()
{
	if (buttonEventFun)
		buttonEventFun();
}

void ClickButton::setButtonEventFun(std::function<void()>&& eventFun)
{
	buttonEventFun = std::forward<std::function<void()>>(eventFun);
}

