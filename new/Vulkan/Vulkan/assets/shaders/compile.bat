cd C:\Program Files\VulkanSDK\1.3.296.0\Bin

call glslc.exe C:\dev\C++\Vulkan\Vulkan\assets\shaders\shader.vert -o C:\dev\C++\Vulkan\Vulkan\assets\shaders\vert.spv
call glslc.exe C:\dev\C++\Vulkan\Vulkan\assets\shaders\shader.frag -o C:\dev\C++\Vulkan\Vulkan\assets\shaders\frag.spv


call glslc.exe C:\dev\C++\Vulkan\Vulkan\assets\shaders\shader_texture.vert -o C:\dev\C++\Vulkan\Vulkan\assets\shaders\texture_vert.spv
call glslc.exe C:\dev\C++\Vulkan\Vulkan\assets\shaders\shader_texture.frag -o C:\dev\C++\Vulkan\Vulkan\assets\shaders\texture_frag.spv

PAUSE