#include "Scene/sceneBase.h"


class SceneMenu : public SceneBase 
{
public:
	int buttonXOffset;
	int buttonYOffset;
	QPixmap background;
	QPixmap startButtonBackground;
	QPixmap knapsackButtonBackground;
	QPixmap setButtonBackground;
	QPixmap exitButtonBackground;
	ClickButton* btnStart;
	ClickButton* btnKnapsack;
	ClickButton* btnSet;
	ClickButton* btnExit;

	Q_OBJECT
public:
	explicit SceneMenu(QWidget* parent = nullptr);
	~SceneMenu() override;

};