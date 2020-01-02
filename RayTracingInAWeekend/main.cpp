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
#include "global.hpp"
#include "diffuse.hpp"
#include "metal.hpp"
#include "dielectric.hpp"

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

vec3 color(const ray& r, hitable *obj, int depth) {
    hit_record rec;
    if (obj->hit(r, 0.001, MAXFLOAT, rec)) {
        ray scattered;
        vec3 attenuation;
        //depth
        if (depth < 10 && rec.mat_ptr->scatter(r, rec, attenuation, scattered)) {
            return attenuation * color(scattered, obj, depth+1);
        } else {
            return vec3(0, 0, 0);
        }

    } else {
        vec3 unit_dir = unit_vector(r.direction());
        float t = 0.5 * (unit_dir.y() + 1.0);
        return (1.0-t)*vec3(1, 1, 1) + t*vec3(0.5, 0.7, 1.0);
    }
}

hitable *random_scene()
{
    int n = 500;
    hitable **list = new hitable*[n+1];
    list[0] = new sphere(vec3(0, -1000, 0), 1000, new diffuse(vec3(0.5, 0.5, 0.5)));
    int i = 1;
    for (int a = -11; a < 11; a++) {
        for (int b = -11; b < 11; b++) {
            float choose_mat = drand48();
            vec3 center(a + 0.9 * drand48(), 0.2, 0.9 * drand48());
            if ((center - vec3(4, 0.2, 0)).length() > 0.9) {
                if (choose_mat < 0.8) {
                    list[i++] = new sphere(center, 0.2, new diffuse(vec3(drand48()*drand48(), drand48()*drand48(), drand48()*drand48())));
                }
                else if (choose_mat < 0.95) {
                    list[i++] = new sphere(center, 0.2, new metal(vec3(0.5*(1+drand48()), 0.5*(1+drand48()), 0.5*(1+drand48())), 0.5));
                }
                else
                {
                    list[i++] = new sphere(center, 0.2, new dielectric(1.5));
                }
            }
        }
    }
    return new hitable_list(list, i);
}

int main(int argc, const char * argv[]) {
     int nx = 200;
     int ny = 300;
    int ns = 100;
    
    hitable *list = random_scene();

    vec3 **data;
    data = new vec3 *[nx];
    for (int index = 0; index < ny; index++) {
        data[index] = new vec3[ny];
    }
    
    camera cam(vec3(-2, 2, 1), vec3(0, 0, -1), vec3(0, 1, 0), 90, (float)nx/(float)ny);
    std::cout << "P3\n" << nx << " " << ny << "\n255\n";
    for (int j = ny - 1; j >= 0; j--) {
        for (int i = 0; i<nx; i++) {
            vec3 col(0, 0, 0);
            //anti-aliasing
            for (int s = 0; s < ns; s++) {
                float u = (float)(i+drand48())/(float)(nx);
                float v = (float)(j+drand48())/(float)(ny);
                ray r = cam.get_ray(u, v);

                col += color(r, list, 0);
            }
            col /= ns;
            //gamma correct
            col = vec3(sqrt(col.x()), sqrt(col.y()), sqrt(col.z()));
            
            int ir = int(255*col.x());
            int ig = int(255*col.y());
            int ib = int(255*col.z());
            data[i][j] = vec3(ir, ig, ib);
        }
    }

    PPMUtil::WritePPMFile(nx, ny, data);
    return 0;
}
