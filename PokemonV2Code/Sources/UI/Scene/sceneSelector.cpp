#include "Core/PlayPokemon/playPokemon.h"
#include "UI/Scene/sceneSelector.h"
#include "UI/Scene/sceneMenu.h"


QString SceneSelector::sceneName = "SceneSelector";

SceneSelector::SceneSelector(QWidget* parent) : SceneBase(parent)
{
	// 初始化QPixmap
	selectorBaseground = globalPicture->getPixmap(globalString->selectorBackground);
	selectorPokemonPixmap1P = PlayPokemon::playPokemon1P->getSelectorPokemonPixmap();
	selectorPokemonPixmap2P = PlayPokemon::playPokemon2P->getSelectorPokemonPixmap();
	returnButton = globalPicture->getPixmap(globalString->returnButton);

	// 窗口背景
	QPalette paletteWindow;
	paletteWindow.setBrush(QPalette::Window, QBrush(selectorBaseground));
	setPalette(paletteWindow);

	// === 绘制 ===
	// 宝可梦


	// 按钮
	// 返回按钮
	std::pair<int, int> returnButtonPosition = {sceneWidth - returnButton.width() - 25, sceneHeight - returnButton.height() - 20};
	btnReturn = new ClickButton(this);
	btnReturn->setButtonPixmap(returnButton);
	btnReturn->setButtonPosition(returnButtonPosition);
	btnReturn->setButtonEventFun([&]() {
		emit requestSwitchScene(SceneMenu::sceneName);
		});
}

SceneSelector::~SceneSelector()
{

}
