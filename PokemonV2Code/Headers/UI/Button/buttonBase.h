#pragma once

#include <qpushbutton.h>
#include <qpixmap.h>
#include <qpainter.h>
#include <iostream>

class ButtonBase : public QPushButton
{
	Q_OBJECT
protected:
	std::pair<int, int> buttonPosition;
	QPixmap buttonPixmap;


public:
	explicit ButtonBase(QWidget* parent = nullptr);
	virtual void setButtonPixmap(const QPixmap& pix);
	virtual void setButtonPosition(std::pair<int, int> Position);

protected:
	void paintEvent(QPaintEvent* event) override;

};