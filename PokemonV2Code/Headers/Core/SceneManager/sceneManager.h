#pragma once 

#include <QStackedWidget>
#include <QHash>
#include <QObject>
#include "Core/SceneManager/sceneRegistry.h"


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

    bool switchScene(const QString& sceneName, const QVariantMap& params = {});

    SceneBase* getCurrentScene() const { return currentScene; }

private:
    explicit SceneManager(QStackedWidget* container, QObject* parent = nullptr);

    SceneBase* createScene(const QString& sceneName);

    QStackedWidget* container;
    QHash<QString, SceneBase*> sceneCache;
    SceneBase* currentScene = nullptr;

signals:
    void sceneSwitched(const QString& fromId, const QString& toId);
};