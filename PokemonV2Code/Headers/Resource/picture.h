#pragma once

#include <QDebug>
#include <QHash>
#include <QImage>
#include <QPixmap>
#include "resourceStringName.h"

#include <vector>


class Picture
{
private:
	// QPixmap is GUI-related and should be created/used in the GUI thread.
	// We load resources as QImage in worker threads, and convert to QPixmap lazily in GUI thread.
	QHash<QString, QImage>	imageHash;
	QHash<QString, QPixmap>	pixmapCache;
	QHash<QString, QString> pathHash;

public:
	Picture(const Picture& obj) = delete;
	Picture& operator=(const Picture& obj) = delete;
	static Picture* getInstance();
	void loadPixmap(const QString& pixmapName, const QString& picturePath);
	void loadPixmap(const QString& picturePath);
	QPixmap getPixmap(const QString& pixmapName);
	std::vector<QPixmap> getPixmapList(const std::pair<QString, int>& pictureStringList);
	void loadPixmapList(const QString& picturePathTemplate, int pictureNum);

private:
	Picture();

};
