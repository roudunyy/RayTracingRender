//
//  camera.hpp
//  RayTracingInAWeekend
//
//  Created by kid jason on 2020/1/2.
//  Copyright © 2020年 kid jason. All rights reserved.
//

#ifndef camera_hpp
#define camera_hpp

#include <stdio.h>
#include "ray.hpp"

class camera
{
public:
    camera() {
        orig = vec3(0, 0, 0);
        horizontal = vec3(4, 0, 0);
        vertical = vec3(0, 6, 0);
        lower_left = vec3(-2, -3, -1);
    }
    
    ray get_ray(float u, float v) {
        return ray(orig, lower_left + u*horizontal + v*vertical - orig);
    }
public:
    vec3 orig;
    vec3 lower_left;
    vec3 horizontal;
    vec3 vertical;
    
};
#endif /* camera_hpp */
