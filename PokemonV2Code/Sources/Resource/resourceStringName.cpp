#include "Resource/resourceStringName.h"
#include "util.h"


ResourceStringName::ResourceStringName()
{
	// scene
	backgroundBase = "backgroundBase";
	menuBackground = "menuBackground";
	selectorBackground = "selectorBackground";

	// button
	startButton = "startButton";
	knapsackButton = "knapsackButton";
	setButton = "setButton";
	exitButton = "exitButton";

	// sceneSelector
	pokeball = "pokeball";

	// pokemon
	loadStringList(Bulbasaur, ":/Pokemon/selector_bulbasaur_%1", 2);
	loadStringList(Charmander, ":/Pokemon/selector_charmander_%1", 2);
	loadStringList(Squirtle, ":/Pokemon/selector_squirtle_%1", 2);
}

ResourceStringName* ResourceStringName::getInstance()
{
	static ResourceStringName globalString;
	return &globalString;
}

void ResourceStringName::loadStringList(std::vector<QString>& stringList, const QString& picturePathTemplate, int pictureNum)
{
	for (int i = 0; i < pictureNum; ++i)
	{
		QString picturePath = picturePathTemplate.arg(i + 1);
		QString pixmapName = Util::pathToLowerCamelCase(picturePath);
		stringList.emplace_back(pixmapName);
	}
}
