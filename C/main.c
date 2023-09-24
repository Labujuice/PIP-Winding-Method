#include <stdio.h>
#include "PIP_winding.h"

int main(void)
{
    // 0. load testing point 
    ll_point_i32_s testpoint[2] = { [0].lat = 247701340, [0].lon = 1210299470,
                                    [1].lat = 247703620, [1].lon = 1210298640
                                    };
    printf("test point num = %ld\n", sizeof(testpoint)/(2*sizeof(int32_t)));

    // 1. load polygon file
    polygon_fence_s geofence = {.point_number = 3, .inclusion = 1, 
                            .point[0].lat = 247703700, .point[0].lon = 1210299120,
                            .point[1].lat = 247700960, .point[1].lon = 1210299730,
                            .point[2].lat = 247702130, .point[2].lon = 1210296730
                            };

    // 2. Check the polygon poing valid
    if(PIP_check_polygon_is_valid_WGS84(geofence))
    {
        printf("geofence point check OK~\n");
    }
    else
    {
        printf("geofence point check NG~\n");
        return 1;
    }
    
    //for continueous calculating by realtime position updating.
    while(true)
    {
        static uint8_t test_num = 0;
        // 3. confirm the position and check valid
        if(!check_WGS84_point_valid(testpoint[test_num]))
        {
            printf("test poing not valid! \n");
            return 1;
        }

        // 4. determine the target point inside or outside






        test_num++;
        if(test_num >= sizeof(testpoint)/(2*sizeof(int32_t)))
        {
            break;
        }
        
    }
    return 0;
}