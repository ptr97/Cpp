#include "MapPoint.h"
#include "MapDistance.h"
#include <iostream>
#include <cmath>

int MapPoint::next_free_id = 1;


MapPoint::MapPoint()
{

}

void MapPoint::print() const
{
	std::cout << "Point with ID=" << _id << " : (" << _latitude << ", " << _longitude << ")" << std::endl;
}

void MapPoint::set_coordinates(const double longitude, const double latitude)
{
	_longitude = longitude;
	_latitude = latitude;
}

void MapPoint::assign_id()
{
	_id = next_free_id;
	++next_free_id;
}

void MapPoint::set_longitude(const double longitude)
{
	_longitude = longitude;
}

void MapPoint::set_latitude(const double latitude)
{
	_latitude = latitude;
}

MapDistance MapPoint::distance(const MapPoint& point)
{
	double longitude = fabs(_longitude - point._longitude);
	double latitude = fabs(_latitude - point._latitude);

	MapDistance distance = MapDistance(longitude, latitude);
	return distance;
}

MapPoint& MapPoint::closest(MapPoint& point1, MapPoint& point2)
{
	int longitude1 = pow(_longitude - point1._longitude, 2);
	int latitude1 = pow(_latitude - point1._latitude, 2);

	int difference1 = sqrt(longitude1 + latitude1);


	int longitude2 = pow(_longitude - point2._longitude, 2);
	int latitude2 = pow(_latitude - point2._latitude, 2);

	int difference2 = sqrt(longitude2 + latitude2);

	return difference1 < difference2 ? point1 : point2;
}
