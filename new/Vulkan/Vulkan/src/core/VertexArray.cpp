#include "VertexArray.h"

namespace WMC {

	/* 绑定描述 */
	VkVertexInputBindingDescription VertexArray::getBindingDescription()
	{
		VkVertexInputBindingDescription bindingDescription{};

		/**
		* 我们所有的每个顶点数据都打包在一个数组中，因此我们只有一个绑定。
		*  binding 参数指定绑定数组中绑定的索引。
		*  stride 参数指定从一个条目到下一个条目的字节数，
		*  inputRate 参数可以具有以下值之一：
		*    VK_VERTEX_INPUT_RATE_VERTEX：移动到每个顶点之后的下一个数据条目
		*	 VK_VERTEX_INPUT_RATE_INSTANCE：在每个实例之后移动到下一个数据条目
		*/
		bindingDescription.binding = 0;
		bindingDescription.stride = sizeof(Vertex);
		bindingDescription.inputRate = VK_VERTEX_INPUT_RATE_VERTEX;

		return bindingDescription;
	}

	/* 属性描述 */
	std::array<VkVertexInputAttributeDescription, 3> VertexArray::getAttributeDescriptions()
	{
		std::array<VkVertexInputAttributeDescription, 3> attributeDescriptions{};

		/**
		* binding 参数告诉 Vulkan 每个顶点数据的绑定来自哪个。
		*  location 参数引用顶点着色器中输入的位置指令。位置为 0 的顶点着色器中的输入是位置，
		*  它有两个 32 位浮点分量。
		*   float:VK_FORMAT_R32_SFLOAT
		*   vec2:VK_FORMAT_R32G32_SFLOAT
		*   vec3:VK_FORMAT_R32G32B32_SFLOAT
		*   vec4:VK_FORMAT_R32G32B32A32_SFLOAT
		*/
		attributeDescriptions[0].binding = 0;
		attributeDescriptions[0].location = 0;

		/**
		* 如您所见，您应该使用颜色通道数量与 shader 数据类型中的组件数量匹配的格式。
		* 允许使用比着色器中的组件数量更多的通道，但它们将被静默丢弃。如果通道数小于元件数，
		* 则 BGA 元件将使用默认值 （0， 0， 1）。颜色类型 （SFLOAT、UINT、SINT） 和位宽也应与着色器输入的类型匹配。
		* 
		* ivec2：一个 32 位有符号整数的 2 分量向量VK_FORMAT_R32G32_SINT
		* uvec4：一个 32 位无符号整数的 4 分量向量VK_FORMAT_R32G32B32A32_UINT
		* double：双精度（64 位）浮点数VK_FORMAT_R64_SFLOAT
		*/
		attributeDescriptions[0].format = VK_FORMAT_R32G32B32_SFLOAT;
		attributeDescriptions[0].offset = offsetof(Vertex, pos);

		attributeDescriptions[1].binding = 0;
		attributeDescriptions[1].location = 1;
		attributeDescriptions[1].format = VK_FORMAT_R32G32B32_SFLOAT;
		attributeDescriptions[1].offset = offsetof(Vertex, color);

		attributeDescriptions[2].binding = 0;
		attributeDescriptions[2].location = 2;
		attributeDescriptions[2].format = VK_FORMAT_R32G32_SFLOAT;
		attributeDescriptions[2].offset = offsetof(Vertex, texCoord);

		return attributeDescriptions;
	}

}