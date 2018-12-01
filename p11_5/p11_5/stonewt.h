#ifndef STONEWT_H_INCLUDED
#define STONEWT_H_INCLUDED
#pragma once
#include <iostream> 

class Stonewt
{
private:
	enum Mode {STN, ISTN, STLB};
	enum {Lbs_per_stn=14};
	int stone;
	double pds_left;
	double pounds;
	Mode form;
public:
	Stonewt(double lbs);
	Stonewt(int stn, double lbs);
	Stonewt();
	~Stonewt() {};
	void changeM(Mode k=ISTN);
	Stonewt operator+(const Stonewt & a) const;
	Stonewt operator-(const Stonewt & a) const;
	Stonewt operator*(double n) const;
	//friend function
	friend Stonewt operator*(double n, const Stonewt & a);
	friend std::ostream & operator<<(std::ostream & co, const Stonewt & a);
};











#endif