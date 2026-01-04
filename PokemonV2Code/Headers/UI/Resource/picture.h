#pragma once

#include <qpixmap.h>
#include <qpalette.h>
#include <qdebug.h>
#include "resourceStringName.h"


class Picture
{
private:
	QHash<QString, QPixmap>	pixmapHash;
	QHash<QString, QString> pathHash;

public:
	Picture(const Picture& obj) = delete;
	Picture& operator=(const Picture& obj) = delete;
	static Picture* getInstance();
	void loadPixmap(const QString& pixmapName, const QString& picturePath);
	QPixmap getPixmap(const QString& pixmapName);

private:
	Picture();

};