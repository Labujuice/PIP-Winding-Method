#include "PIP_winding.h"

bool check_WGS84_point_valid(ll_point_i32_s target)
{
    if ((target.lat >= -900000000) && (target.lat <= 900000000) && (target.lon >= -1800000000) && (target.lon <= 1800000000))
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool check_point_is_same(ll_point_i32_s target_A, ll_point_i32_s target_B)
{
    if ((target_A.lat == target_B.lat) && (target_A.lon == target_B.lon))
    {
        return true; // same point
    }
    else
    {
        return false; // different point
    }
}

bool PIP_check_polygon_is_valid_WGS84(polygon_fence_s target)
{
    if (target.point_number < 3)
    {
        return false;
    }

    for (uint8_t cnt = 0; cnt < target.point_number; cnt++)
    {
        if (check_WGS84_point_valid(target.point[cnt]) == false)
        {
            return false;
        }

        if ((cnt + 1) != target.point_number)
        {
            if (check_point_is_same(target.point[cnt], target.point[cnt + 1]) == true) // compare with next point
            {
                return false;
            }
        }
        else // cnt == target.point_number
        {
            if (check_point_is_same(target.point[cnt], target.point[0]) == true) // compare with first poin
            {
                return false;
            }
        }
    }

    return true;
}