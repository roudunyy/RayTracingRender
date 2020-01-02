//
//  diffuse.hpp
//  RayTracingInAWeekend
//
//  Created by kid jason on 2020/1/2.
//  Copyright © 2020年 kid jason. All rights reserved.
//

#ifndef diffuse_hpp
#define diffuse_hpp

#include <stdio.h>
#include "material.hpp"
#include "global.hpp"

class diffuse : public material
{
public:
    diffuse(const vec3& a) : albedo(a) {}
    
    virtual bool scatter(const ray& r_in, const hit_record& rec, vec3& attenuation, ray& scattered) const {
        vec3 target = rec.p + rec.normal + random_in_unit_sphere();
        scattered = ray(rec.p, target-rec.p);
        attenuation = albedo;
        return true;
    }
    
    
public:
    vec3 albedo;
};
#endif /* diffuse_hpp */
