#pragma once

namespace Orange
{

	template <typename T> struct hash;

	class UUID
	{
	public:
		UUID();
		UUID(uint64_t uuid);
		UUID(const UUID&) = default;

		uint64_t Get() { return o_UUID; }

		operator uint64_t() const { return o_UUID; }
	private:
		uint64_t o_UUID;
	};

}


namespace std
{

	template <>
	struct hash<Orange::UUID>
	{
		std::size_t operator()(const Orange::UUID& uuid) const
		{
			return (uint64_t)uuid;
		}
	};

}
