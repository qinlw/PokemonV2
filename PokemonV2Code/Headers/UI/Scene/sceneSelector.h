#include "Ui/Scene/sceneBase.h"


class SceneSelector : public SceneBase {
	Q_OBJECT
public:
	// 场景名
	static QString sceneName;
private:
	// 背景
	QPixmap selectorBaseground;

public:
	explicit SceneSelector(QWidget* parent = nullptr);
	~SceneSelector() override;
	QString getSceneName() const override { return sceneName; }
	static QString staticSceneName() { return sceneName; }
};