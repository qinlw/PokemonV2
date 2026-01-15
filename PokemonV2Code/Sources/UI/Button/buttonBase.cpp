#include "UI/Button/buttonBase.h"


ButtonBase::ButtonBase(QWidget* parent) : QPushButton(parent)
{
	setFlat(true);
	setFocusPolicy(Qt::NoFocus);
	setAutoFillBackground(true);
}

void ButtonBase::setButtonPixmap(const QPixmap& pixmap)
{
	buttonPixmap = pixmap;
	setFixedSize(pixmap.size());
	QPalette palette;
	palette.setBrush(QPalette::Button, QBrush(buttonPixmap));
	setPalette(palette);
	update();
}

void ButtonBase::setButtonPosition(std::pair<int, int> position)
{
	buttonPosition = position;
	move(buttonPosition.first, buttonPosition.second);
	update();
}

void ButtonBase::paintEvent(QPaintEvent* event)
{
	QPushButton::paintEvent(event);
	if (!buttonPixmap.isNull()) {
		QPainter painter(this);
		painter.drawPixmap(rect(), buttonPixmap);
	}
}
