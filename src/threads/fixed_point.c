#include <stdint.h>

#define q 16
#define f (1 << q)

typedef int fixed_point;

//convert an integer to its fixed point representation
fixed_point int_to_fixed(int x) 
{
    return (int)x * f;
}

//convert fixed point to integer rounded towards zero
int fixed_to_int_floor(fixed_point x) 
{
    return x / f;
}

//convert fixed point to integer rounded towards the nearest integer
int fixed_to_int_round(fixed_point x) 
{
    if (x >= 0)
        return (x + (f/2)) / f;
        
    return (x - (f/2)) / f;
}

//add two fixed point numbers
fixed_point fixed_add(fixed_point x, fixed_point y) 
{
    return x + y;
}

//subtract two fixed point numbers
fixed_point fixed_subtract(fixed_point x, fixed_point y) 
{ 
    return x - y;
}

//add fixed point to an integer
fixed_point int_fixed_add(fixed_point x, int n)
{
    return x + (n * f);
}

//subtract fixed point from an integer
fixed_point int_fixed_sub(int n, fixed_point x) 
{
    return x - (n * f);
}

//multiply two fixed point numbers
fixed_point fixed_multiply(fixed_point x, fixed_point y) 
{
    return (int)(((int64_t)x) * y / f);
}

//divide two fixed point numbers
fixed_point fixed_divide(fixed_point x, fixed_point y) 
{
    return (int)(((int64_t)x) * f / y);
}

//multiply an integer by fixed point
fixed_point int_fixed_mul(fixed_point x, int n)
{
    return x * n;
}

//divide an integer by fixed point
fixed_point int_fixed_div(fixed_point x, int n)
{
    return x / n;
}
