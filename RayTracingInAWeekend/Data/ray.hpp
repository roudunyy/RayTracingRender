//
//  ray.hpp
//  RayTracingInAWeekend
//
//  Created by kid jason on 2019/12/31.
//  Copyright © 2019年 kid jason. All rights reserved.
//

#ifndef ray_hpp
#define ray_hpp

#include <stdio.h>
#include "vec3.hpp"

class ray
{
public:
    ray() {}
    ray(const vec3 &a, const vec3 &b) { A = a; B = b;}
    vec3 origin() const {return A;}
    vec3 direction() const {return B;}
    vec3 point_at_param(float t) const {return (A + t * B);}
    
    vec3 A;
    vec3 B;
};

#endif /* ray_hpp */
