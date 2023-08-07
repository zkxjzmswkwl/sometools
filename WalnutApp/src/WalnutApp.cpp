#include "Walnut/Application.h"
#include "Walnut/EntryPoint.h"

#include "XORLayer.h"

#include <Windows.h>
#include <shellapi.h>




Walnut::Application* Walnut::CreateApplication(int argc, char** argv)
{
	Walnut::ApplicationSpecification spec;
	spec.Name = "some tools";
	spec.CustomTitlebar = true;
	spec.Height = 240;
	spec.Width = 480;

	Walnut::Application* app = new Walnut::Application(spec);
	std::shared_ptr<XORLayer> xorLayer = std::make_shared<XORLayer>();
	app->PushLayer(xorLayer);
	app->SetMenubarCallback([app, xorLayer]()
		{
			if (ImGui::BeginMenu("About"))
			{
				if (ImGui::MenuItem("Repository"))
				{
					ShellExecute(0, 0, "https://github.com/zkxjzmswkwl/sometools", 0, 0, SW_SHOW);
			}
			ImGui::EndMenu();
		}
	});
	return app;
}
