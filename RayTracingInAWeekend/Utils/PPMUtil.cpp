//
//  PPMUtil.cpp
//  RayTracingInAWeekend
//
//  Created by kid jason on 2019/12/31.
//  Copyright © 2019年 kid jason. All rights reserved.
//

#include "PPMUtil.hpp"
#include <iostream>
#include <fstream>

using namespace std;
void PPMUtil::WritePPMFile(int row, int cols, vec3 **data)
{
    ofstream outputFile;
    outputFile.open("result.ppm");
    
    outputFile << "P3\n" << row << " " << cols << "\n255\n" << endl;
    for (int j = cols - 1; j >= 0; j--) {
        for (int i = 0; i<row; i++) {
      
            outputFile<<data[i][j]<< "\n";
        }
    }
    outputFile.close();
    
}
