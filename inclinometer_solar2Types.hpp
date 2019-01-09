#ifndef SOLAR2_TYPES_HPP
#define SOLAR2_TYPES_HPP

#include <base/Time.hpp>

namespace solar2 {
	struct Inclination
	{
		base::Time time;
		double x;
		double y;
	};

}

#endif

