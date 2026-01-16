#include "UI/Scene/sceneMenu.h"
#include "UI/Scene/sceneSelector.h"


QString SceneMenu::sceneName = "SceneMenu";

SceneMenu::SceneMenu(QWidget* parent) : SceneBase(parent)
{
    // 初始化pixmap
    menuBackground = globalPicture->getPixmap(globalString->menuBackground);
    startButton = globalPicture->getPixmap(globalString->startButton);
    knapsackButton = globalPicture->getPixmap(globalString->knapsackButton);
    setButton = globalPicture->getPixmap(globalString->setButton);
    exitButton = globalPicture->getPixmap(globalString->exitButton);

    // 初始化偏移量
    buttonXOffset = -38;
    buttonYOffset = (sceneHeight - startButton.height()  * 4) / 5;

    // 窗口背景
    QPalette paletteWindow;
    paletteWindow.setBrush(QPalette::Window, QBrush(menuBackground));
    setPalette(paletteWindow);

    // 按钮
    // 开始按钮
    std::pair<int, int> startButtonPosition = { sceneWidth - startButton.width() + buttonXOffset, buttonYOffset };
    btnStart = new ClickButton(this);
    btnStart->setButtonPixmap(startButton);
    btnStart->setButtonPosition(startButtonPosition);
    btnStart->setButtonEventFun([&]() {
        emit requestSwitchScene(SceneSelector::sceneName);
        });
    // 背包按钮
    std::pair<int, int> knapsackButtonPosition = { startButtonPosition.first, startButtonPosition.second + startButton.height() + buttonYOffset };
    btnKnapsack = new ClickButton(this);
    btnKnapsack->setButtonPixmap(knapsackButton);
    btnKnapsack->setButtonPosition(knapsackButtonPosition);
    // 设置按钮
    std::pair<int, int> setButtonPosition = { startButtonPosition.first, knapsackButtonPosition.second + startButton.height() + buttonYOffset };
    btnSet = new ClickButton(this);
    btnSet->setButtonPixmap(setButton);
    btnSet->setButtonPosition(setButtonPosition);
    // 退出按钮
    std::pair<int, int> exitButtonPosition = { startButtonPosition.first, setButtonPosition.second + startButton.height() + buttonYOffset };
    btnExit = new ClickButton(this);
    btnExit->setButtonPixmap(exitButton);
    btnExit->setButtonPosition(exitButtonPosition);
    btnExit->setButtonEventFun([&]() {
        exit(0);
        });
}

SceneMenu::~SceneMenu() 
{

}