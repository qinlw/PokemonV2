#include "UI/Scene/sceneSelector.h"


QString SceneSelector::sceneName = "SceneSelector";

SceneSelector::SceneSelector(QWidget* parent) : SceneBase(parent)
{
	// 初始化QPixmap
	selectorBaseground = globalPicture->getPixmap(globalString->selectorBackground);

	// 窗口背景
	QPalette paletteWindow;
	paletteWindow.setBrush(QPalette::Window, QBrush(selectorBaseground));
	setPalette(paletteWindow);
}

SceneSelector::~SceneSelector()
{

}
