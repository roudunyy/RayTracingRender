//
//  PPMUtil.hpp
//  RayTracingInAWeekend
//
//  Created by kid jason on 2019/12/31.
//  Copyright © 2019年 kid jason. All rights reserved.
//

#ifndef PPMUtil_hpp
#define PPMUtil_hpp

#include <stdio.h>
#include "vec3.hpp"

class PPMUtil
{
public:
    static void WritePPMFile(int row, int cols, vec3 **data);
    
};
#endif /* PPMUtil_hpp */
