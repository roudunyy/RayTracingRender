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
    sphere(vec3 cen, float r, material *mat) : center(cen), radius(r), m_mat(mat) {};
    virtual bool hit(const ray& r, float t_min, float t_max, hit_record &result) const;
public:
    vec3 center;
    float radius;
    material *m_mat;
};


#endif /* sphere_hpp */
