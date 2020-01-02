//
//  global.hpp
//  RayTracingInAWeekend
//
//  Created by kid jason on 2020/1/2.
//  Copyright © 2020年 kid jason. All rights reserved.
//

#ifndef global_hpp
#define global_hpp

#include <stdio.h>
#include "vec3.hpp"

vec3 random_in_unit_sphere();

float schlick(float cosine, float ref_idx);
#endif /* global_hpp */
