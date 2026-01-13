#pragma once

#include "Scene/sceneBase.h"
#include <QMap>
#include <functional>


using SceneCreator = std::function<SceneBase* ()>;

class SceneRegistry
{
public:
    static SceneRegistry* instance() {
        static SceneRegistry inst;
        return &inst;
    }

    void registerSceneCreator(const QString& sceneId, const SceneCreator& creator) {
        m_creators[sceneId] = creator;
    }

    SceneCreator getSceneCreator(const QString& sceneId) {
        return m_creators.value(sceneId, nullptr);
    }

private:
    SceneRegistry() = default;
    QMap<QString, SceneCreator> m_creators;
};