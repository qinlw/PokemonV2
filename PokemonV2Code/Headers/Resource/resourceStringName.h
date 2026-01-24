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
	QString returnButton;
	QString pokeball;
	// Pokemon
	std::pair<QString, int> selectorBulbasaur;
	std::pair<QString, int> selectorCharmander;
	std::pair<QString, int> selectorSquirtle;
	std::pair<QString, int> bulbasaur;
	std::pair<QString, int> charmander;
	std::pair<QString, int> squirtle;
	QString bulbasaurHeadPortraitRight;
	QString charmanderHeadPortraitRight;
	QString squirtleHeadPortraitRight;

public:
	ResourceStringName(const ResourceStringName& obj) = delete;
	ResourceStringName& operator=(const ResourceStringName& obj) = delete;
	static ResourceStringName* getInstance();
	void loadStringList(std::pair<QString, int>& pictureStringList, const QString& picturePathTemplate, int pictureNum);

private:
	ResourceStringName();

};
