#include "ogpch.h"
#include "UUID.h"

#include <random>

#include <unordered_map>

namespace Orange
{

	static std::random_device o_RendomDevice;
	static std::mt19937_64 o_Engine(o_RendomDevice());
	static std::uniform_int_distribution<uint64_t> o_UniformDistribution;

	UUID::UUID()
		: o_UUID(o_UniformDistribution(o_Engine))
	{
	}

	UUID::UUID(uint64_t uuid)
		: o_UUID(uuid)
	{
	}

}
