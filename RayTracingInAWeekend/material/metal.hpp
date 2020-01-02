//
//  metal.hpp
//  RayTracingInAWeekend
//
//  Created by kid jason on 2020/1/2.
//  Copyright © 2020年 kid jason. All rights reserved.
//

#ifndef metal_hpp
#define metal_hpp

#include <stdio.h>
#include "material.hpp"
#include "global.hpp"

class metal : public material
{
public:
    metal(const vec3& a, float rough) : albedo(a) { roughness = (rough > 1 ? 1 : rough);}
    virtual bool scatter(const ray& r_in, const hit_record& rec, vec3& attenuation, ray& scattered) const {
        vec3 reflected = reflect(unit_vector(r_in.direction()), rec.normal);
        scattered = ray(rec.p, reflected + roughness * random_in_unit_sphere());
        attenuation = albedo;
        return dot(scattered.direction(), rec.normal)>0;
    }
public:
    vec3 albedo;
    float roughness;
};
#endif /* metal_hpp */
