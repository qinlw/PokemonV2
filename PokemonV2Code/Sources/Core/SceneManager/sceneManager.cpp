#pragma once

#include "SceneManager/sceneManager.h"
#include <QDebug>

SceneManager::SceneManager(QStackedWidget* container, QObject* parent)
    : QObject(parent), container(container)
{
}

SceneBase* SceneManager::createScene(const QString& sceneId)
{
    if (sceneCache.contains(sceneId)) {
        return sceneCache[sceneId];
    }

    SceneCreator creator = SceneRegistry::instance()->getSceneCreator(sceneId);
    if (!creator) {
        qWarning() << "[SceneManager] is unregistered£º" << sceneId;
        return nullptr;
    }

    SceneBase* scene = creator();
    if (!scene) {
        qWarning() << "[SceneManager] creation failed£º" << sceneId;
        return nullptr;
    }

    connect(scene, &SceneBase::requestSwitchScene, this, &SceneManager::switchScene);

    container->addWidget(scene);
    sceneCache[sceneId] = scene;

    return scene;
}

bool SceneManager::switchScene(const QString& sceneId, const QVariantMap& params)
{
    if (!container) {
        qWarning() << "[SceneManager] hasn't been initialized";
        return false;
    }

    QString fromId = currentScene ? currentScene->sceneId() : "None";
    if (currentScene) {
        currentScene->onExit();
    }

    SceneBase* targetScene = createScene(sceneId);
    if (!targetScene) {
        return false;
    }

    container->setCurrentWidget(targetScene);
    targetScene->onEnter(params);

    currentScene = targetScene;
    emit sceneSwitched(fromId, sceneId);
    qInfo() << "[SceneManager] switch scene£º" << fromId << " -> " << sceneId;
}