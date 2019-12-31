//
//  main.cpp
//  RayTracingInAWeekend
//
//  Created by kid jason on 2019/12/17.
//  Copyright © 2019年 kid jason. All rights reserved.
//

#include <iostream>
#include "ray.hpp"
#include "PPMUtil.hpp"

float hit_sphere(const vec3 &center, float radius, const ray& r) {
    vec3 oc = r.origin() - center;
    float a = dot(r.direction(), r.direction());
    float b = 2.0 * dot(oc, r.direction());
    float c = dot(oc, oc) - radius * radius;
    float discriminant = b*b - 4*a*c;
    if (discriminant < 0) {
        return -1;
    } else {
        return (-b-sqrt(discriminant))/(2*a);
    }

}

vec3 color(const ray& r) {
    float t = hit_sphere(vec3(0, 0, -1), 0.5, r);
    if (t > 0) {
        vec3 N = unit_vector(r.point_at_param(t)- vec3(0,0,-1));
        return 0.5*vec3(N.x()+1, N.y()+1, N.z()+1);
    }
    vec3 unit_dir = unit_vector(r.direction());
    t = 0.5 * (unit_dir.y() + 1.0);
    return (1.0-t)*vec3(1, 1, 1) + t*vec3(0.5, 0.7, 1.0);
}


int main(int argc, const char * argv[]) {
     int nx = 200;
     int ny = 300;
    
    vec3 lower_left(-2, -3, -1);
    vec3 horizontal(4, 0, 0);
    vec3 vertical(0, 6, 0);
    vec3 orig(0, 0, 0);
    vec3 **data;
    data = new vec3 *[nx];
    for (int index = 0; index < ny; index++) {
        data[index] = new vec3[ny];
    }
    std::cout << "P3\n" << nx << " " << ny << "\n255\n";
    for (int j = ny - 1; j >= 0; j--) {
        for (int i = 0; i<nx; i++) {
            float u = (float)i/(float)(nx);
            float v = (float)j/(float)(ny);
            ray r(orig, lower_left + u*horizontal + v*vertical);
            vec3 col = color(r);
            
            int ir = int(255*col.x());
            int ig = int(255*col.y());
            int ib = int(255*col.z());
            data[i][j] = vec3(ir, ig, ib);
        }
    }

    PPMUtil::WritePPMFile(nx, ny, data);
    return 0;
}
