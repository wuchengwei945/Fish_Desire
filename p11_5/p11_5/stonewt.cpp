#include "pch.h"
#include <iostream>
#include "stonewt.h"

using std::ostream;
using std::cout;
using std::endl;

//only the construct function can be initialized by use the memberlist 
Stonewt::Stonewt()
{
	stone = pounds = pds_left = 0;
	form = LBS;
}

Stonewt::Stonewt(double lbs)
{
	form = LBS;
	pounds = lbs;
	stone = int(lbs) / Lbs_per_stn;
	pds_left = int(lbs) % Lbs_per_stn + lbs - int(lbs);
}

Stonewt::Stonewt(int stn, double lbs)
{
	form = STLBS;
	stone = stn;
	pds_left = lbs;
	pounds = stn * Lbs_per_stn + lbs;
}

void Stonewt::changeM(Mode k)
{
	form = k;
}

Stonewt Stonewt::operator+(const Stonewt & a) const
{
	//Stonewt result;
	return Stonewt(pounds + a.pounds);
}

Stonewt Stonewt::operator-(const Stonewt & a) const
{
	return Stonewt(pounds - a.pounds);
}

Stonewt Stonewt::operator*(double n) const
{
	return Stonewt(pounds*n);
}

Stonewt operator*(double n, const Stonewt & a)
{
	return a * n;
}

ostream & operator<<(ostream & co, const Stonewt & a)
{
	switch (a.form)
	{
	case Stonewt::LBS:
		co << a.pounds << " pounds" << endl;
		break;
	case Stonewt::ILBS:
		co << int(a.pounds) << " pounds(int)" << endl;
		break;
	case Stonewt::STLBS:
		co << a.stone << " stones " << a.pds_left << " pounds" << endl;
		break;
	}
}
