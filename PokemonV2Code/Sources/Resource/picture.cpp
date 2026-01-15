#include "Resource/picture.h"


Picture::Picture()
{
	// scene
	loadPixmap("background", ":/Scene/menu_background");

	// button
	loadPixmap("startButtonBackground", ":/Button/start_button");
	loadPixmap("knapsackButtonBackground", ":/Button/knapsack_button");
	loadPixmap("setButtonBackground", ":/Button/set_button");
	loadPixmap("exitButtonBackground", ":/Button/exit_button");
}

Picture* Picture::getInstance()
{
	static Picture globalPicture;
	return &globalPicture;
}

void Picture::loadPixmap(const QString& pixmapName, const QString& picturePath)
{
	QPixmap pixmap(picturePath);
	if (pixmap.isNull())
	{
		qWarning() << QString("pixmap load fail: name: %1, path: %2").arg(pixmapName).arg(picturePath);
	}
	else
	{
		pixmapHash.insert(pixmapName, pixmap);
		pathHash.insert(pixmapName, picturePath);
	}
}

QPixmap Picture::getPixmap(const QString& pixmapName)
{
	if (pixmapHash.find(pixmapName) != pixmapHash.end())
		return pixmapHash[pixmapName];
	else
		qWarning() << QString("pixmap get fail: name: %1").arg(pixmapName);

	return QPixmap();
}
