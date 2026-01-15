#include "UI/Scene/sceneSelector.h"


QString SceneSelector::sceneName = "SceneSelector";

SceneSelector::SceneSelector(QWidget* parent) : SceneBase(parent)
{
	// ³õÊ¼»¯QPixmap
	selectorBaseground = globalPicture->getPixmap(globalString->selectorBackground);

	// ´°¿Ú±³¾°
	QPalette paletteWindow;
	paletteWindow.setBrush(QPalette::Window, QBrush(selectorBaseground));
	setPalette(paletteWindow);
}

SceneSelector::~SceneSelector()
{

}
