#pragma once

#include <QString>


class ResourceStringName
{
public:
	QString background;
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