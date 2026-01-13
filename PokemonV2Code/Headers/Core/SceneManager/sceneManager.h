#pragma once 

#include "SceneManager/sceneRegistry.h"
#include <QStackedWidget>
#include <QMap>
#include <QObject>

class SceneManager : public QObject
{
    Q_OBJECT
public:
    static SceneManager& instance(QStackedWidget* container = nullptr) {
        static SceneManager inst(container);
        return inst;
    }

    SceneManager(const SceneManager&) = delete;
    SceneManager& operator=(const SceneManager&) = delete;

    bool switchScene(const QString& sceneId, const QVariantMap& params = {});

    SceneBase* getCurrentScene() const { return currentScene; }

signals:
    void sceneSwitched(const QString& fromId, const QString& toId);

private:
    explicit SceneManager(QStackedWidget* container, QObject* parent = nullptr);

    SceneBase* createScene(const QString& sceneId);

    QStackedWidget* container;
    QMap<QString, SceneBase*> sceneCache;
    SceneBase* currentScene = nullptr;
};