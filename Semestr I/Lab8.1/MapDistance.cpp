#include "MapDistance.h"
#include <iostream>



// MapDistance::MapDistance()
// {
// 	_diff_longitude = 0;
// 	_diff_latitude = 0;
// }


MapDistance::MapDistance(double diff_longitude, double diff_latitude)
{
	_diff_longitude = diff_longitude;
	_diff_latitude = diff_latitude;
}

void MapDistance::print()
{
	std::cout << "Distance: (" << _diff_longitude << ", " << _diff_latitude << ")" << std::endl;
}
