//
//  hitable.hpp
//  RayTracingInAWeekend
//
//  Created by kid jason on 2019/12/31.
//  Copyright © 2019年 kid jason. All rights reserved.
//

#ifndef hitable_hpp
#define hitable_hpp

#include <stdio.h>
#include "ray.hpp"

class material;

struct hit_record {
    float t;
    vec3 p;
    vec3 normal;
    material *mat_ptr;
};

class hitable
{
public:
    virtual bool hit(const ray& r, float t_min, float t_max, hit_record &result) const = 0;
};

#endif /* hitable_hpp */
