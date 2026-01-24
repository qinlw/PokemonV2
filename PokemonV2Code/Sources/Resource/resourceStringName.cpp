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
	returnButton = Util::pathToLowerCamelCase(":/Scene/SceneSelector/return_button");
	pokeball = Util::pathToLowerCamelCase(":/Scene/SceneSelector/pokeball");

	// pokemon
	loadStringList(selectorBulbasaur, ":/Pokemon/selector_bulbasaur_%1", 2);
	loadStringList(selectorCharmander, ":/Pokemon/selector_charmander_%1", 2);
	loadStringList(selectorSquirtle, ":/Pokemon/selector_squirtle_%1", 2);
	loadStringList(bulbasaur, ":/Pokemon/bulbasaur_%1", 2);
	loadStringList(charmander, ":/Pokemon/charmander_%1", 2);
	loadStringList(squirtle, ":/Pokemon/squirtle_%1", 2);
	bulbasaurHeadPortraitRight = Util::pathToLowerCamelCase(":/Pokemon/bulbasaur_head_portrait_right");
	charmanderHeadPortraitRight = Util::pathToLowerCamelCase(":/Pokemon/charmander_head_portrait_right");
	squirtleHeadPortraitRight = Util::pathToLowerCamelCase(":/Pokemon/squirtle_head_portrait_right");
}

ResourceStringName* ResourceStringName::getInstance()
{
	static ResourceStringName globalString;
	return &globalString;
}

void ResourceStringName::loadStringList(std::pair<QString, int>& pictureStringList, const QString& picturePathTemplate, int pictureNum)
{
	pictureStringList.first = Util::pathToLowerCamelCase(picturePathTemplate);
	pictureStringList.second = pictureNum;
}
