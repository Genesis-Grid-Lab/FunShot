#include <FunShot.h>
#include "Engine/Core/EntryPoint.h"

#include "EditorLayer.h"

namespace FS {

    class FunShotEditor : public Application{
    public:
        FunShotEditor()
            : Application("FunShot Editor"){            
            PushLayer(new EditorLayer());
        }
        ~FunShotEditor() {}
    };

    Application* CreateApplication(){
        return new FunShotEditor();
    }
}