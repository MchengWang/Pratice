#include <Orange.h>
#include <Orange/Core/EntryPoint.h>

#include "EditorLayer.h"

namespace Orange
{

	class Orangefruit : public Orange::Application
	{
	public:
		Orangefruit(const ApplicationSpecification& spec)
			: Application(spec)
		{
			PushLayer(new EditorLayer());
		}

	};

	Application* CreateApplication(ApplicationCommandLineArgs args)
	{
		ApplicationSpecification spec;
		spec.Name = "Orangefruit";
		spec.CommandLineArgs = args;
		return new Orangefruit(spec);
	}
}
