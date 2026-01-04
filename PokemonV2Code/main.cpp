#include "Scene/sceneMenu.h"

#include <qapplication.h>


int main(int argc, char* argv[])
{
    QApplication app(argc, argv);

    SceneMenu sceneMenu;
    sceneMenu.show();

    return app.exec();
}
