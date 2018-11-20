#ifndef VECTOR_H_INCLUDED
#define VECTOR_H_INCLUDED
#include <iostream>

namespace VECTOR{

    class Vector
    {
    public:
        enum Mode{RECT, POL};
    private:
        double x;
        double y;
        //double mag;
        //double ang;
        Mode mode;
		/*
        void set_mag();
        void set_ang();
        void set_x();
        void set_y();
		*/
    public:
        Vector();
        Vector(double n1, double n2, Mode form= RECT);
        void reset(double n1, double n2, Mode form=RECT);
		~Vector(){};
        double xval() const {return x;}
        double yval() const { return y;}
		double magval() const;
		double angval() const;
        void polar_mode();
        void rect_mode();
        Vector operator+(const Vector & b) const;
        Vector operator-(const Vector & b) const;
        Vector operator-() const;
        Vector operator*(double n) const;
		operator double() const;
        //friends
        friend Vector operator*(double n, const Vector & a);
        friend std::ostream & operator <<(std::ostream & co, const Vector & v);

    };

};
#endif // VECTOR_H_INCLUDED
