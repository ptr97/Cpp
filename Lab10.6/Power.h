#pragma once


template<int VAL>
struct TooLargeNumberMustBeSmallerThan10 {};

template<>
struct TooLargeNumberMustBeSmallerThan10 <10>;


template <int a, int n>
class Power
{
public:
	static const int Value = a * Power<a, (n > 0) ? (n-1) : (n+1)>::Value;
	TooLargeNumberMustBeSmallerThan10<n> x;
};

template<int a>
class Power<a, 1>
{
public:
	static const int Value = a;
};


template<int a>
class Power<a, 0>
{
public:
	static const int Value = 1;
};


template<int a>
class Power<a, -1>
{
public:
	static const int Value = 0;
};
