#pragma once 

class Angle
{
public:
	static Angle fromRadians(const double radians);
	static Angle fromDegrees(const double degrees);
	
	double toRad() const;
	double toDeg() const;

	Angle(const Angle& angle);

	Angle& add(const Angle& angle);

	static Angle distance(const Angle& ang1, const Angle& ang2);

	operator int() const;

private:
	Angle();
	Angle(const double angle);

	double m_radians;
};

