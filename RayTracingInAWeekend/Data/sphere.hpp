//
//  sphere.hpp
//  RayTracingInAWeekend
//
//  Created by kid jason on 2019/12/31.
//  Copyright © 2019年 kid jason. All rights reserved.
//

#ifndef sphere_hpp
#define sphere_hpp

#include <stdio.h>
#include "hitable.hpp"
class sphere : public hitable
{
public:
    sphere() {}
    sphere(vec3 cen, float r) : center(cen), radius(r) {};
    virtual bool hit(const ray& r, float t_min, float t_max, hit_record &result) const;
public:
    vec3 center;
    float radius;
    
};

bool sphere::hit(const ray &r, float t_min, float t_max, hit_record &result) const
{
    vec3 oc = r.origin() - center;
    float a = dot(r.direction(), r.direction());
    float b = dot(oc, r.direction());
    float c = dot(oc, oc) - radius * radius;
    float discriminant = b*b -a*c;
    if (discriminant > 0) {
        float temp = (-b - sqrt(b*b-a*c))/a;
        if (temp < t_max && temp > t_min) {
            result.t = temp;
            result.p = r.point_at_param(result.t);
            result.normal = (result.p - center) / radius;
            return true;
        }
        temp = (-b + sqrt(b*b-a*c))/a;
        if (temp < t_max && temp > t_min) {
            result.t = temp;
            result.p = r.point_at_param(result.t);
            result.normal = (result.p - center) / radius;
            return true;
        }
    }
    return false;
}
#endif /* sphere_hpp */
