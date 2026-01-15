#include "Resource/resourceStringName.h"


ResourceStringName::ResourceStringName()
{
	// scene
	background = "background";
	menuBackground = "menuBackground";
	selectorBackground = "selectorBackground";
	// button
	startButtonBackground = "startButtonBackground";
	knapsackButtonBackground = "knapsackButtonBackground";
	setButtonBackground = "setButtonBackground";
	exitButtonBackground = "exitButtonBackground";
}

ResourceStringName* ResourceStringName::getInstance()
{
	static ResourceStringName globalString;
	return &globalString;
}