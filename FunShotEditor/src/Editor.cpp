#include <FunShot.h>
#include "EditorLayer.h"

namespace FS {
    class Editor : public Application{
    public:
        Editor(){
            PushLayer(new EditorLayer());
        }
        ~Editor() {}
    };


    Application* CreateApplication(){
        return new Editor();
    }

}