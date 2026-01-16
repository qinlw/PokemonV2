#pragma once

#include <QHash>
#include <functional>
#include "UI/Scene/sceneBase.h"


using SceneCreator = std::function<SceneBase* ()>;

class SceneRegistry
{
public:
    static SceneRegistry* instance() {
        static SceneRegistry inst;
        return &inst;
    }

    void registerSceneCreator(const QString& sceneName, const SceneCreator& creator) {
        creators[sceneName] = creator;
    }

    SceneCreator getSceneCreator(const QString& sceneName) {
        return creators.value(sceneName, static_cast<SceneCreator>(nullptr));
    }

private:
    SceneRegistry() = default;
    QHash<QString, SceneCreator> creators;

};