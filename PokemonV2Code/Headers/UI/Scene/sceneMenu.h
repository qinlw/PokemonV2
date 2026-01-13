#include "Scene/sceneBase.h"


class SceneMenu : public SceneBase
{
protected:
	// 按钮偏移量
	int buttonXOffset;
	int buttonYOffset;
	// 背景
	QPixmap background;
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

	Q_OBJECT
public:
	explicit SceneMenu(QWidget* parent = nullptr);
	~SceneMenu() override;
	QString sceneId() const override { return "SceneMenu"; }
	static QString staticSceneId() { return "MenuScene"; }

};