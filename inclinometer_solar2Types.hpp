#ifndef INCLINOMETER_SOLAR2_TYPES_HPP
#define INCLINOMETER_SOLAR2_TYPES_HPP

#include <base/Time.hpp>
#include <base/Eigen.hpp>

namespace inclinometer_solar2 {
	struct Inclinations
	{
		/** Timestamp of the orientation reading */
		base::Time time;

		/** raw inclinometer reading*/
		base::Vector3d inc;
	};

}

#endif
