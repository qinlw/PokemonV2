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

    void registerSceneCreator(const QString& sceneId, const SceneCreator& creator) {
        creators[sceneId] = creator;
    }

    SceneCreator getSceneCreator(const QString& sceneId) {
        return creators.value(sceneId, nullptr);
    }

private:
    SceneRegistry() = default;
    QHash<QString, SceneCreator> creators;
};