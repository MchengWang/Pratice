#pragma once

#include "Orange/Core/Buffer.h"

namespace Orange {

	class FileSystem
	{
	public:
		// TODO: move to FileSystem class
		static Buffer ReadFileBinary(const std::filesystem::path& filepath);
	};

}
