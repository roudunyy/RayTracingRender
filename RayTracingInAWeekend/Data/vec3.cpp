//
//  vec3.cpp
//  RayTracingInAWeekend
//
//  Created by kid jason on 2019/12/31.
//  Copyright © 2019年 kid jason. All rights reserved.
//

#include "vec3.hpp"

vec3 operator+(const vec3 &v1, const vec3 &v2) {
    return vec3(v1.x()+v2.x(), v1.y()+v2.y(), v1.z()+v2.z());
}

vec3 operator-(const vec3 &v1, const vec3 &v2) {
    return vec3(v1.x()-v2.x(), v1.y()-v2.y(), v1.z()-v2.z());
}

vec3 operator*(const vec3 &v1, const vec3 &v2) {
    return vec3(v1.x()*v2.x(), v1.y()*v2.y(), v1.z()*v2.z());
}

 vec3 operator/(const vec3 &v1, const vec3 &v2) {
    return vec3(v1.x()/v2.x(), v1.y()/v2.y(), v1.z()/v2.z());
}

 vec3 operator*(float t, const vec3 &v1) {
    return vec3(t*v1.x(), t*v1.y(), t*v1.z());
}

 vec3 operator*(const vec3 &v1, float t) {
    return vec3(t*v1.x(), t*v1.y(), t*v1.z());
}

 vec3 operator/(const vec3 &v1, float t) {
    return vec3(v1.x()/t, v1.y()/t,  v1.z()/t);
}

 float dot(const vec3 &v1, const vec3 &v2) {
    return v1.x()*v2.x() + v1.y()*v2.y() + v1.z()*v2.z();
    
}

 vec3 cross(const vec3 &v1, const vec3 &v2) {
    return vec3(v1.y()*v2.z() - v1.z()*v2.y(),
                (-(v1.x()*v2.z() - v1.z() *v2.x())),
                v1.x()*v2.y() - v1.y()*v2.x());
    
}

vec3 unit_vector(const vec3& v) {
    return vec3(v.x()/v.length(), v.y()/v.length(), v.z()/v.length());
}

std::ostream& operator<<(std::ostream &os, const vec3 &t) {
    os<< t.x() << " " << t.y() << " " << t.z();
    return os;
}

//inline std::istream& operator>>(std::istream &is, vec3 &t) {
//    is >> t.x() >> t.y() >> t.z();
//    return is;
//}
