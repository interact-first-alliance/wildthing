#include "Constants.h"

/**
 * interface to take in a value and map it to the desired range
 * @param x - the inputted value
 * @param in_min - the minimum the inputed value can be
 * @param in_max - the maximum the inputed value can be
 * @param out_min - the minimum the outputed value can be
 * @param out_max - the maximum the outputed value can be
 * @return the mapped value
*/
double mapf(double x, double in_min, double in_max, double out_min, double out_max)
{
    return (x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min;
}
