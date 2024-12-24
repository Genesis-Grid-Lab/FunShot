#include <FunShot.h>
#include "GameLayer.h"
#include "Editor/EditorLayer.h"

class Game : public FS::Application{
public:
    Game(){                
        PushLayer(new GameLayer());
        // PushOverlay(new FS::EditorLayer());
    }
    ~Game() {}
};


FS::Application* FS::CreateApplication(){
    return new Game();
}