#include "Ui/Scene/sceneBase.h"


class SceneSelector : public SceneBase {
	Q_OBJECT
public:
	// 场景名
	static QString sceneName;
private:
	// 背景
	QPixmap selectorBaseground;
	// 宝可梦
	std::vector<QPixmap> selectorPokemonPixmap1P;
	std::vector<QPixmap> selectorPokemonPixmap2P;
	// 返回按钮
	QPixmap returnButton;
	ClickButton* btnReturn;

public:
	explicit SceneSelector(QWidget* parent = nullptr);
	~SceneSelector() override;
	QString getSceneName() const override { return sceneName; }
	static QString staticSceneName() { return sceneName; }
};
