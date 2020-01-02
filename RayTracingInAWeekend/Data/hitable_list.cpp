//
//  hitable_list.cpp
//  RayTracingInAWeekend
//
//  Created by kid jason on 2020/1/2.
//  Copyright © 2020年 kid jason. All rights reserved.
//

#include "hitable_list.hpp"

bool hitable_list::hit(const ray &r, float t_min, float t_max, hit_record &result) const
{
    float closest = t_max;
    hit_record tempRecord;
    bool hit_any = false;
    for (int i=0; i<size; i++) {
        if (objList[i]->hit(r, t_min, closest, tempRecord)) {
            closest = tempRecord.t;
            result = tempRecord;
            hit_any = true;
        }
    }
    return hit_any;
}
