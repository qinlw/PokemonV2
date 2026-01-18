#pragma once

#include <QString>


class ResourceStringName
{
public:
	// scene
	QString backgroundBase;
	QString menuBackground;
	QString selectorBackground;
	// button	
	QString startButton;
	QString knapsackButton;
	QString setButton;
	QString exitButton;
	// SceneSelector
	QString pokeball;
	// Pokemon
	std::vector<QString> selectorBulbasaur;
	std::vector<QString> selectorCharmander;
	std::vector<QString> selectorSquirtle;

public:
	ResourceStringName(const ResourceStringName& obj) = delete;
	ResourceStringName& operator=(const ResourceStringName& obj) = delete;
	static ResourceStringName* getInstance();
	void loadStringList(std::vector<QString>& stringList, const QString& picturePathTemplate, int pictureNum);

private:
	ResourceStringName();

};
