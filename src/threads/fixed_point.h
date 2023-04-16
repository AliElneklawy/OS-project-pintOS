#ifndef FIXED_POINT_H
#define FIXED_POINT_H

#include <stdint.h>

#define FIXED_POINT_BITS 16
#define FIXED_POINT_ONE (1 << FIXED_POINT_BITS)

typedef int fixed_point;

fixed_point int_to_fixed(int x);
int fixed_to_int(fixed_point x);
fixed_point fixed_add(fixed_point x, fixed_point y);
fixed_point fixed_subtract(fixed_point x, fixed_point y);
fixed_point fixed_multiply(fixed_point x, fixed_point y);
fixed_point fixed_divide(fixed_point x, fixed_point y);

#endif // FIXED_POINT_H
