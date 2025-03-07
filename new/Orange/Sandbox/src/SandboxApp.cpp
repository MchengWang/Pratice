#include <Orange.h>
#include <Orange/Core/EntryPoint.h>

#include "Sandbox2D.h"

#include "ExampleLayer.h"

class Sandbox : public Orange::Application
{
public:
	Sandbox(const Orange::ApplicationSpecification& specification)
		: Orange::Application(specification)
	{
		PushLayer(new Sandbox2D());
	}

	~Sandbox()
	{

	}

};

Orange::Application* Orange::CreateApplication(Orange::ApplicationCommandLineArgs args)
{
	ApplicationSpecification spec;
	spec.Name = "Sandbox";
	spec.WorkingDirectory = "../Hazelnut";
	spec.CommandLineArgs = args;
	return new Sandbox(spec);
}
