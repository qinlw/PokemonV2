#include "UI/Scene/sceneBase.h"


class SceneMenu : public SceneBase
{
	Q_OBJECT
public:
	// 场景名
	static QString sceneName;
private:
	// 按钮偏移量
	int buttonXOffset;
	int buttonYOffset;
	// 背景
	QPixmap menuBackground;
	// 开始按钮
	QPixmap startButtonBackground;
	ClickButton* btnStart;
	// 背包按钮
	QPixmap knapsackButtonBackground;
	ClickButton* btnKnapsack;
	// 设置按钮
	QPixmap setButtonBackground;
	ClickButton* btnSet;
	// 退出按钮
	QPixmap exitButtonBackground;
	ClickButton* btnExit;

public:
	explicit SceneMenu(QWidget* parent = nullptr);
	~SceneMenu() override;
	QString getSceneName() const override { return sceneName; }
	static QString staticSceneName() { return sceneName; }

};