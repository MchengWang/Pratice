#include "ogpch.h"

#include "Orange/Renderer/RenderCommand.h"

namespace Orange
{

	Scope<RendererAPI> RenderCommand::o_RendererAPI = RendererAPI::Create();

}