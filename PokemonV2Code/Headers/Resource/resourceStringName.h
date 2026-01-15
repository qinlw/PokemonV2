#pragma once

#include <QString>


class ResourceStringName
{
public:
	// scene
	QString background;
	QString menuBackground;
	QString selectorBackground;
	// button	
	QString startButtonBackground;
	QString knapsackButtonBackground;
	QString setButtonBackground;
	QString exitButtonBackground;

public:
	ResourceStringName(const ResourceStringName& obj) = delete;
	ResourceStringName& operator=(const ResourceStringName& obj) = delete;
	static ResourceStringName* getInstance();

private:
	ResourceStringName();

};