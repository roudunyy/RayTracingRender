//
//  hitable_list.hpp
//  RayTracingInAWeekend
//
//  Created by kid jason on 2020/1/2.
//  Copyright © 2020年 kid jason. All rights reserved.
//

#ifndef hitable_list_hpp
#define hitable_list_hpp

#include <stdio.h>
#include "hitable.hpp"

class hitable_list : public hitable
{
public:
    hitable_list() {}
    hitable_list(hitable **list, int n) { objList = list; size = n;}
    virtual bool hit(const ray& r, float t_min, float t_max, hit_record &result) const;
    
public:
    hitable **objList;
    int size;
    
};

#endif /* hitable_list_hpp */
