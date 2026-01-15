#include "Ui/Scene/sceneBase.h"


class SceneSelector : public SceneBase {
	Q_OBJECT
public:
	// ³¡¾°Ãû
	static QString sceneName;
private:
	// ±³¾°
	QPixmap selectorBaseground;

public:
	explicit SceneSelector(QWidget* parent = nullptr);
	~SceneSelector() override;
	QString getSceneName() const override { return sceneName; }
	static QString staticSceneName() { return sceneName; }
};