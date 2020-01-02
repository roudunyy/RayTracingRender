//
//  dielectric.hpp
//  RayTracingInAWeekend
//
//  Created by kid jason on 2020/1/2.
//  Copyright © 2020年 kid jason. All rights reserved.
//

#ifndef dielectric_hpp
#define dielectric_hpp

#include <stdio.h>
#include "material.hpp"
#include "global.hpp"

class dielectric : public material
{
public:
    dielectric(float ri) : ref_index(ri) {}
    
    virtual bool scatter(const ray& r_in, const hit_record& rec, vec3& attenuation, ray& scattered) const
    {
        vec3 outward_normal;
        vec3 reflected = reflect(r_in.direction(), rec.normal);
        float ni_over_nt;
        attenuation = vec3(1.0, 1.0, 1.0);
        vec3 refracted;
        float reflect_prob;
        float cosine;
        
        if (dot(r_in.direction(), rec.normal) > 0) {
            outward_normal = -rec.normal;
            ni_over_nt = ref_index;
            cosine = ref_index * dot(r_in.direction(), rec.normal)/r_in.direction().length();
        } else {
            outward_normal = rec.normal;
            ni_over_nt = 1.0 / ref_index;
              cosine = -dot(r_in.direction(), rec.normal)/r_in.direction().length();
        }
        if (refract(r_in.direction(), outward_normal, ni_over_nt, refracted)) {
//            scattered = ray(rec.p, refracted);
            reflect_prob = schlick(cosine, ref_index);
        } else {
            scattered = ray(rec.p, reflected);
            reflect_prob = 1;
//            return false;
        }
        if (drand48() < reflect_prob) {
              scattered = ray(rec.p, reflected);
        } else {
               scattered = ray(rec.p, refracted);
        }
        return true;
    }
public:
    float ref_index;
    
};
#endif /* dielectric_hpp */
