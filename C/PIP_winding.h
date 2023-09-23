#ifndef PIP_WINDING_H_
#define PIP_WINDING_H_

#include <stdint.h>
#include <stdbool.h>


typedef struct
{
    int32_t lat;
    int32_t lon;
}ll_point_i32_s; //Lat-Lon-Point

typedef struct
{
    ll_point_i32_s point[256]; //point of a polygon
    uint8_t point_number; //point number of a polygon (3~255)
    uint8_t inclusion; // 0: inside is forbidden, 1: allow inside 
}polygon_fence_s;

typedef struct
{
    int8_t winding_cnt;
    bool inside; //0: outside, 1: inside
}pip_result_s;
#endif