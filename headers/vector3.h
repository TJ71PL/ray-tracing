#ifndef VECTOR3_H
#define VECTOR3_H

#include <iostream>
#include <cmath>

class vector3{

public:
    // variables 
    double a[3];

    // constructors
    vector3() : a{0,0,0} {} 

    vector3(double x, double y, double z) : a{x,y,z} {};

    //acess specifiers 
    double x() const{
        return a[0];
    }

    double y() const{
        return a[1];
    }

    double z() const{
        return a[2];
    }

    //operator overloading
    vector3 operator-() const{
        return vector3(-a[0],-a[1],-a[2]);
    }

    // read only
    double operator[](int i) const{
        return a[i];
    }

    // read and write through the address
    double& operator[](int i ){
        return a[i];
    }

    vector3& operator+=(const vector3& v){
        a[0] += v.a[0];
        a[1] += v.a[1];
        a[2] += v.a[2];
        return *this;
    }

    vector3& operator*=(double multiplier){
        a[0] *= multiplier;
        a[1] *= multiplier;
        a[2] *= multiplier;
        return *this;
    }

    vector3& operator/=(double divider){
        return *this *= 1/divider;
    }

    double lenght_squared() const{
        return (a[0]*a[0]+a[1]*a[1]+a[2]*a[2]);
    }

    double lenght() const{
        return sqrt(lenght_squared());
    }
};

// alais
using point3 = vector3;

// vector utiliites

// inline reffers to executing the funciton without funciton call but 
// the function is expanded where ever it is called 

inline std::ostream& operator<<(std::ostream& out, const vector3& v){
    return out << v.a[0] << ' ' << v.a[1] << ' ' << v.a[2];
}

inline vector3 operator+(const vector3& x, const vector3& y){
    return vector3(x.a[0]+y.a[0],x.a[1]+y.a[1],x.a[2]+y.a[2]);
}

inline vector3 operator-(const vector3& x, const vector3& y){
    return vector3(x.a[0]-y.a[0],x.a[1]-y.a[1],x.a[2]-y.a[2]);
}

inline vector3 operator*(const vector3& x, const vector3& y){
    return vector3(x.a[0]*y.a[0],x.a[1]*y.a[1],x.a[2]*y.a[2]);
}

inline vector3 operator*(double multiplier, const vector3& v){
    return vector3(multiplier*v.a[0],multiplier*v.a[1],multiplier*v.a[2]);
}

inline vector3 operator*(const vector3& v, double multiplier){
    return multiplier * v;
}

inline vector3 operator/(const vector3& v, double divider){
    return (1/divider)*v;
}

inline vector3 unit_vector(const vector3& v){
    return v/v.lenght();
}

inline double dot(const vector3& x, const vector3& y){
    return (x.a[0]*y.a[0]+x.a[1]*y.a[1]*x.a[2]*y.a[2]);
}

inline vector3 cross(const vector3& x, const vector3& y){
    return vector3(x.a[1]*y.a[2]-x.a[2]*y.a[1],
                   x.a[2]*y.a[0]-x.a[0]*y.a[2],
                   x.a[0]*y.a[1]-x.a[1]*y.a[0]);
}

#endif