#pragma once

#include "Core/SceneManager/sceneManager.h"
#include <QDebug>

SceneManager::SceneManager(QStackedWidget* container, QObject* parent)
    : QObject(parent), container(container)
{
}

SceneBase* SceneManager::createScene(const QString& sceneName)
{
    if (sceneCache.contains(sceneName)) {
        return sceneCache[sceneName];
    }

    SceneCreator creator = SceneRegistry::instance()->getSceneCreator(sceneName);
    if (!creator) {
        qWarning() << "[SceneManager] is unregistered：" << sceneName;
        return nullptr;
    }

    SceneBase* scene = creator();
    if (!scene) {
        qWarning() << "[SceneManager] creation failed：" << sceneName;
        return nullptr;
    }

    connect(scene, &SceneBase::requestSwitchScene, this, &SceneManager::switchScene);

    container->addWidget(scene);
    sceneCache[sceneName] = scene;

    return scene;
}

bool SceneManager::switchScene(const QString& sceneName, const QVariantMap& params)
{
    if (!container) {
        qWarning() << "[SceneManager] hasn't been initialized";
        return false;
    }

    QString fromId = currentScene ? currentScene->getSceneName() : "None";
    if (currentScene) {
        currentScene->onExit();
    }

    SceneBase* targetScene = createScene(sceneName);
    if (!targetScene) {
        return false;
    }

    container->setCurrentWidget(targetScene);
    targetScene->onEnter(params);

    currentScene = targetScene;
    emit sceneSwitched(fromId, sceneName);
    qInfo() << "[SceneManager] switch scene：" << fromId << " -> " << sceneName;
}