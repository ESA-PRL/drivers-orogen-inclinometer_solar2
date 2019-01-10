#ifndef INCLINOMETER_SOLAR2_TYPES_HPP
#define INCLINOMETER_SOLAR2_TYPES_HPP

#include <base/Time.hpp>

namespace inclinometer_solar2 {
	struct Inclinations
	{
		base::Time time;
		float x;
		float y;
	};

}

#endif

