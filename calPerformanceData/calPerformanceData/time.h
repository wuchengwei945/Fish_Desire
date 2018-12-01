#pragma once
#ifndef TIME_H_INCLUDED
#define TIME_H_INCLUDED
#include <iostream>

class Time
{
private:
	int hour;
	int minute;
	int second;
	const static int LOT = 8;
	const static int REV = 60;
public:
	//Time();
	Time(const char * ct);
	Time(int h=0, int min=0, int s=0);
	bool operator<(const Time & a) const;
	bool operator>(const Time & a) const;
	bool operator==(const Time & a) const;
//friend function
	friend Time operator*(double n, const Time & b);
	friend Time operator*(const Time & b, double n);
	friend Time operator+(const Time & a, const Time & b);
	friend Time operator-(const Time & a, const Time & b);
	friend std::ostream & operator<<(std::ostream & co, const Time & a);
	friend std::istream & operator>>(std::istream & ci, Time & a);

};

#endif // !TIME_H_INCLUDED

