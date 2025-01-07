#include <FunShot.h>
#include <Engine/Core/EntryPoint.h>

#include "EditorLayer.h"

namespace FS {

	class Editor : public Application
	{
	public:
		Editor(ApplicationCommandLineArgs args)
			: Application("Editor", args)
		{
			PushLayer(new EditorLayer());
		}

		~Editor()
		{
		}
	};

	Application* CreateApplication(ApplicationCommandLineArgs args)
	{
		return new Editor(args);
	}

}
