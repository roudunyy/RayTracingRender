//
//  global.cpp
//  RayTracingInAWeekend
//
//  Created by kid jason on 2020/1/2.
//  Copyright © 2020年 kid jason. All rights reserved.
//

#include "global.hpp"

vec3 random_in_unit_sphere() {
    vec3 p;
    do {
        p = 2.0 * vec3(drand48(), drand48(), drand48()) - vec3(1, 1, 1);
        
    } while (p.square_length() >= 1.0);
    return p;
}


float schlick(float cosine, float ref_idx)
{
    float r0 = (1-ref_idx) / (1+ref_idx);
    r0 = r0*r0;
    return r0 + (1-r0)*pow((1-cosine), 5);
}
