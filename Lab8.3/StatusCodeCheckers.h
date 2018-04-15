#pragma once

class StatusCodeCheckers
{
public:
	static bool gtzero(int val);
	static bool alwaysTrue(int val);
};


bool StatusCodeCheckers::gtzero(int val)
{
	return val >= 0;
}

bool StatusCodeCheckers::alwaysTrue(int)
{
	return true;
}
