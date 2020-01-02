//
//  main.cpp
//  RayTracingInAWeekend
//
//  Created by kid jason on 2019/12/17.
//  Copyright © 2019年 kid jason. All rights reserved.
//

#include <iostream>
#include "PPMUtil.hpp"
#include "hitable_list.hpp"
#include "sphere.hpp"
#include "camera.hpp"

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

vec3 color(const ray& r, hitable *obj) {
    hit_record rec;
    if (obj->hit(r, 0, MAXFLOAT, rec)) {
        return 0.5*vec3(rec.normal.x()+1, rec.normal.y()+1, rec.normal.z()+1);
    }

    vec3 unit_dir = unit_vector(r.direction());
    float t = 0.5 * (unit_dir.y() + 1.0);
    return (1.0-t)*vec3(1, 1, 1) + t*vec3(0.5, 0.7, 1.0);
}


int main(int argc, const char * argv[]) {
     int nx = 200;
     int ny = 300;
    int ns = 100;
    
    hitable *list[2];
    list[0] = new sphere(vec3(0, 0, -1), 0.5);
    list[1] = new sphere(vec3(0, -100.5, -1), 100);
    hitable *objs = new hitable_list(list, 2);

    vec3 **data;
    data = new vec3 *[nx];
    for (int index = 0; index < ny; index++) {
        data[index] = new vec3[ny];
    }
    
    camera cam;
    std::cout << "P3\n" << nx << " " << ny << "\n255\n";
    for (int j = ny - 1; j >= 0; j--) {
        for (int i = 0; i<nx; i++) {
            vec3 col(0, 0, 0);
            //anti-aliasing
            for (int s = 0; s < ns; s++) {
                float u = (float)(i+drand48())/(float)(nx);
                float v = (float)(j+drand48())/(float)(ny);
                ray r = cam.get_ray(u, v);

                col += color(r, objs);
            }

            int ir = int(255*col.x());
            int ig = int(255*col.y());
            int ib = int(255*col.z());
            data[i][j] = vec3(ir, ig, ib);
        }
    }

    PPMUtil::WritePPMFile(nx, ny, data);
    return 0;
}
