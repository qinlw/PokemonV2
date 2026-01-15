#include "UI/Scene/sceneMenu.h"
#include "UI/Scene/sceneSelector.h"


QString SceneMenu::sceneName = "SceneMenu";

SceneMenu::SceneMenu(QWidget* parent) : SceneBase(parent)
{
    // 初始化pixmap
    menuBackground = globalPicture->getPixmap(globalString->menuBackground);
    startButtonBackground = globalPicture->getPixmap(globalString->startButtonBackground);
    knapsackButtonBackground = globalPicture->getPixmap(globalString->knapsackButtonBackground);
    setButtonBackground = globalPicture->getPixmap(globalString->setButtonBackground);
    exitButtonBackground = globalPicture->getPixmap(globalString->exitButtonBackground);

    // 初始化偏移量
    buttonXOffset = -38;
    buttonYOffset = (sceneHeight - startButtonBackground.height()  * 4) / 5;

    // 窗口背景
    QPalette paletteWindow;
    paletteWindow.setBrush(QPalette::Window, QBrush(menuBackground));
    setPalette(paletteWindow);

    // 按钮
    // 开始按钮
    std::pair<int, int> startButtonPosition = { sceneWidth - startButtonBackground.width() + buttonXOffset, buttonYOffset };
    btnStart = new ClickButton(this);
    btnStart->setButtonPixmap(startButtonBackground);
    btnStart->setButtonPosition(startButtonPosition);
    btnStart->setButtonEventFun([&]() {
        emit requestSwitchScene(SceneSelector::sceneName);
        });
    // 背包按钮
    std::pair<int, int> knapsackButtonPosition = { startButtonPosition.first, startButtonPosition.second + startButtonBackground.height() + buttonYOffset };
    btnKnapsack = new ClickButton(this);
    btnKnapsack->setButtonPixmap(knapsackButtonBackground);
    btnKnapsack->setButtonPosition(knapsackButtonPosition);
    // 设置按钮
    std::pair<int, int> setButtonPosition = { startButtonPosition.first, knapsackButtonPosition.second + startButtonBackground.height() + buttonYOffset };
    btnSet = new ClickButton(this);
    btnSet->setButtonPixmap(setButtonBackground);
    btnSet->setButtonPosition(setButtonPosition);
    // 退出按钮
    std::pair<int, int> exitButtonPosition = { startButtonPosition.first, setButtonPosition.second + startButtonBackground.height() + buttonYOffset };
    btnExit = new ClickButton(this);
    btnExit->setButtonPixmap(exitButtonBackground);
    btnExit->setButtonPosition(exitButtonPosition);
    btnExit->setButtonEventFun([&]() {
        exit(0);
        });
}

SceneMenu::~SceneMenu() 
{

}