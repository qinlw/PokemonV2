#include "Resource/resourceStringName.h"


ResourceStringName::ResourceStringName()
{
	background = "background";
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