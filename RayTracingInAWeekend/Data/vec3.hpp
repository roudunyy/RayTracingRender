//
//  vec3.hpp
//  RayTracingInAWeekend
//
//  Created by kid jason on 2019/12/31.
//  Copyright © 2019年 kid jason. All rights reserved.
//

#ifndef vec3_hpp
#define vec3_hpp

#include <stdio.h>
#include <math.h>
#include <iostream>

class vec3
{
public:
    vec3() {}
    vec3(float x, float y, float z) {num[0] = x; num[1] = y; num[2] = z;};
    inline float x() const {return num[0];}
     inline float y() const {return num[1];}
     inline float z() const {return num[2];}
     inline float r() const {return num[0];}
     inline float g() const {return num[1];}
     inline float b() const {return num[2];}
    
    inline void operator=(const vec3 &v) {num[0] = v.x(); num[1] = v.y(); num[2] = v.z();}
    inline const vec3& operator+() const {return *this;}
    inline vec3 operator-() const {return vec3(-num[0], -num[1], -num[2]);}
    inline float operator[](int i) const {return num[i];}
    inline float& operator[](int i) {return num[i]; }
    
    inline float length() const {
        return sqrt(num[0]*num[0]+num[1]*num[1]+num[2]*num[2]);
    }
    
    inline float square_length() const {
        return (num[0]*num[0]+num[1]*num[1]+num[2]*num[2]);
    }
    
    inline void make_unit_vector() {
        float k = 1.0 / sqrt(num[0]*num[0]+num[1]*num[1]+num[2]*num[2]);
        num[0] *= k; num[1] *= k; num[2] *= k;
    }
    
    inline vec3& operator+=(const vec3 &v) {
        num[0] += v.x();
        num[1] += v.y();
        num[2] += v.z();
        return *this;
    }
    
    inline vec3& operator-=(const vec3 &v) {
        num[0] -= v.x();
        num[1] -= v.y();
        num[2] -= v.z();
        return *this;
    }
    
    inline vec3& operator*=(const vec3 &v) {
        num[0] *= v.x();
        num[1] *= v.y();
        num[2] *= v.z();
        return *this;
    }
    
    inline vec3& operator/=(const vec3 &v) {
        num[0] /= v.x();
        num[1] /= v.y();
        num[2] /= v.z();
        return *this;
    }
    
    inline vec3& operator*=(const float& t) {
        num[0] *= t;
        num[1] *= t;
        num[2] *= t;
        return *this;
    }
    
    inline vec3& operator/=(const float &t) {
        num[0] /= t;
        num[1] /= t;
        num[2] /= t;
        return *this;
    }
//    inline vec3 operator+(const vec3& v1) {
//        return vec3(num[0]+v1.num[0], num[1]+v2.num[1], v1.num[2]+v2.num[2]);
//    }
    
private:
    float num[3];
    
    
};

vec3 operator+(const vec3 &v1, const vec3 &v2);
vec3 operator-(const vec3 &v1, const vec3 &v2);
vec3 operator*(const vec3 &v1, const vec3 &v2);
vec3 operator/(const vec3 &v1, const vec3 &v2);
vec3 operator*(float t, const vec3 &v1);
vec3 operator*(const vec3 &v1, float t);
vec3 operator/(const vec3 &v1, float t);
float dot(const vec3 &v1, const vec3 &v2);
vec3 cross(const vec3 &v1, const vec3 &v2);
std::ostream& operator<<(std::ostream &os, const vec3 &t);
vec3 unit_vector(const vec3& v);

#endif /* vec3_hpp */
