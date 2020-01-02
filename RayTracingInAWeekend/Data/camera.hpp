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
    camera(vec3 pos, vec3 lookat, vec3 up, float vfov, float aspect) {
        vec3 u, v, w;
        float thelta = vfov * M_PI / 180;
        float half_height = tan(thelta/2);
        float half_width = aspect * half_height;
        orig = pos;
        w = unit_vector(pos - lookat);
        u = unit_vector(cross(up, w));
        v = cross(w, u);
        horizontal = 2*half_width*u;
        vertical = 2*half_height*v;
        lower_left = orig - half_width*u - half_height*v - w;
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
