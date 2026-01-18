#include "Resource/resourceStringName.h"
#include "util.h"


ResourceStringName::ResourceStringName()
{
	// scene
	backgroundBase = Util::pathToLowerCamelCase(":/Scene/background_base");
	menuBackground = Util::pathToLowerCamelCase(":/Scene/menu_background");
	selectorBackground = Util::pathToLowerCamelCase(":/Scene/selector_background");

	// button
	startButton = Util::pathToLowerCamelCase(":/Button/start_button");
	knapsackButton = Util::pathToLowerCamelCase(":/Button/knapsack_button");
	setButton = Util::pathToLowerCamelCase(":/Button/set_button");
	exitButton = Util::pathToLowerCamelCase(":/Button/exit_button");

	// sceneSelector
	pokeball = Util::pathToLowerCamelCase(":/Scene/SceneSelector/pokeball");

	// pokemon
	loadStringList(selectorBulbasaur, ":/Pokemon/selector_bulbasaur_%1", 2);
	loadStringList(selectorCharmander, ":/Pokemon/selector_charmander_%1", 2);
	loadStringList(selectorSquirtle, ":/Pokemon/selector_squirtle_%1", 2);
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
