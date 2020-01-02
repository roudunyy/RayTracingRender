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


#endif /* sphere_hpp */
