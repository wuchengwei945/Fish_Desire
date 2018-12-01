#include "pch.h"
#include <iostream>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include "time.h"

using namespace std;

Time::Time(int h, int min, int s) :hour(h), minute(min), second(s)
{

}

//The ct is like 09:54:46
Time::Time(const char * ct)
{
	/*
	char timestr[LOT];
	strcpy(timestr, ct);
	for (int i = 0; i < LOT; i++)
	{
		unsigned long temp = 0;
		if (timestr[i] == ':')
			continue;
		temp+=int(timestr[i]-'0')*
	}
	*/
	if (strlen(ct) > LOT)
	{
		cout << "Bad input of string time!" << endl;
		exit(EXIT_FAILURE);
	}
	int i = 0;
	int j = 0;
	int timearr[7];
	
	while (ct[i] != '\0')
	{
		if (ct[i] == ':')
		{
			i++;
			continue;
		}
		//cout << "ct[i]=" << ct[i] << endl;
		timearr[j] = int(ct[i] - '0');
		//cout << timearr[j] << endl;
		j++;
		i++;
	}
	hour = timearr[0] * 10 + timearr[1];
	minute = timearr[2] * 10 + timearr[3];
	second = timearr[4] * 10 + timearr[5];
}

bool Time::operator<(const Time & a) const
{
	if (hour < a.hour)
		return true;
	else if (minute < a.minute)
		return true;
	else
		return second < a.second;
}

bool Time::operator==(const Time & a) const
{
	return hour == a.hour && minute == a.minute && second == a.second;
}

bool Time::operator>(const Time & a) const
{
	if (*this == a)
		return false;
	else
		return a < *this;
}

Time operator*(double n, const Time & a)
{
	Time result;
	unsigned long temp = a.hour * 3600 + a.minute * 60 + a.second;
	temp *= n;
	result.hour = (temp / 3600) ;
	result.minute = (temp % 3600) / 60;
	result.second = (temp % 3600) % 60;
	return result;
}

Time operator*(const Time & a, double n)
{
	Time result;
	result = n * a;
	return result;
}

Time operator+(const Time & a, const Time & b)
{
	Time result;
	unsigned long temp;
	temp = (a.hour + b.hour) * 3600 + (a.minute + b.minute) * 60 + (a.second + b.second);
	result.hour = temp / 3600;
	result.minute = (temp % 3600) / 60;
	result.second = temp % 60;
	return result;
}

Time operator-(const Time & a, const Time & b)
{
	Time result;
	unsigned long temp;
	temp = (a.hour - b.hour) * 3600 + (a.minute - b.minute) * 60 + (a.second - b.second);
	//cout << a.hour - b.hour << endl;
	//cout << a.minute - b.minute << endl;
	//cout << a.second - b.second << endl;
	//cout << temp << endl;
	result.hour = temp / 3600;
	//cout << result.hour << endl;
	result.minute = (temp % 3600) / 60;
	result.second = temp % 60;
	return result;
}

ostream & operator<<(ostream & co, const Time & a)
{
	co << a.hour << "H" << a.minute << "min" << a.second << "s" << endl;
	return co;
}

istream & operator>>(istream & ci, Time & a)
{
	char * strTime = new char[9];
	//cout << "Time (format like 13:12:11):";
	ci >> strTime;
	a=Time(strTime);
	delete [] strTime;
	return ci;
}