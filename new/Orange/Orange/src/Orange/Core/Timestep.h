#pragma once

namespace Orange
{

	class Timestep
	{
	public:
		Timestep(float time = 0.0f)
			:o_Time(time)
		{
		}

		operator float() const { return o_Time; }

		float GetSeconds() const { return o_Time; }
		float GetMilliseconds() const { return o_Time * 1000.0f; }

	private:
		float o_Time;
	};

}
