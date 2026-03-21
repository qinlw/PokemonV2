#include <QDebug>
#include "Resource/picture.h"
#include "util.h"


Picture::Picture()
{
	// scene
	loadPixmap(":/Scene/background_base");
	loadPixmap(":/Scene/menu_background");
	loadPixmap(":/Scene/selector_background");

	// button
	loadPixmap(":/Button/start_button");
	loadPixmap(":/Button/knapsack_button");
	loadPixmap(":/Button/set_button");
	loadPixmap(":/Button/exit_button");
	
	// sceneSelector
	loadPixmap(":/Scene/SceneSelector/return_button");
	loadPixmap(":/Scene/SceneSelector/pokeball");

	// pokemon
	loadPixmapList(":/Pokemon/selector_bulbasaur_%1", 2);
	loadPixmapList(":/Pokemon/selector_charmander_%1", 2);
	loadPixmapList(":/Pokemon/selector_squirtle_%1", 2);
	loadPixmapList(":/Pokemon/bulbasaur_%1", 2);
	loadPixmapList(":/Pokemon/charmander_%1", 2);
	loadPixmapList(":/Pokemon/squirtle_%1", 2);
	loadPixmap(":/Pokemon/bulbasaur_head_portrait_right");
	loadPixmap(":/Pokemon/charmander_head_portrait_right");
	loadPixmap(":/Pokemon/squirtle_head_portrait_right");
}

Picture* Picture::getInstance()
{
	static Picture globalPicture;
	return &globalPicture;
}

void Picture::loadPixmap(const QString& pixmapName, const QString& picturePath)
{
	QImage image(picturePath);
	if (image.isNull())
	{
		qWarning() << QString("pixmap load fail: name: %1, path: %2").arg(pixmapName).arg(picturePath);
	}
	else
	{
		imageHash.insert(pixmapName, image);
		pixmapCache.remove(pixmapName); // In case of reload
		pathHash.insert(pixmapName, picturePath);
	}
}

void Picture::loadPixmap(const QString& picturePath)
{
	QString pixmapName = Util::pathToLowerCamelCase(picturePath);
	loadPixmap(pixmapName, picturePath);
}

QPixmap Picture::getPixmap(const QString& pixmapName)
{
	auto cachedIt = pixmapCache.find(pixmapName);
	if (cachedIt != pixmapCache.end())
		return cachedIt.value();

	auto imageIt = imageHash.find(pixmapName);
	if (imageIt == imageHash.end()) {
		qWarning() << QString("pixmap get fail: name: %1").arg(pixmapName);
		return QPixmap();
	}

	// Convert QImage -> QPixmap lazily in the caller's thread (expected to be GUI thread).
	QPixmap pixmap = QPixmap::fromImage(imageIt.value());
	pixmapCache.insert(pixmapName, pixmap);
	return pixmap;
}

std::vector<QPixmap> Picture::getPixmapList(const std::pair<QString, int>& pictureStringList)
{
	std::vector<QPixmap> pixmapList;
	for (int i = 0; i < pictureStringList.second; ++i)
	{
		QString pictureString = pictureStringList.first.arg(i);
		QPixmap pixmap = getPixmap(pictureString);
		pixmapList.push_back(pixmap);
	}
	
	return pixmapList;
}

void Picture::loadPixmapList(const QString& picturePathTemplate, int pictureNum)
{
	for (int i = 0; i < pictureNum; ++i)
	{
		QString picturePath = picturePathTemplate.arg(i + 1);
		QString pixmapName = Util::pathToLowerCamelCase(picturePath);
		QImage image(picturePath);
		if (image.isNull())
		{
			qWarning() << QString("pixmap load fail: name: %1, path: %2").arg(pixmapName).arg(picturePath);
		}
		else
		{
			imageHash.insert(pixmapName, image);
			pixmapCache.remove(pixmapName);
			pathHash.insert(pixmapName, picturePath);
		}
	}
}
