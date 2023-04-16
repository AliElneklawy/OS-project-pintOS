#ifndef FIXED_POINT_H
#define FIXED_POINT_H

#include <stdint.h>
#include "threads/fixed_point.h"


// Define the number of bits used to represent the decimal portion of the fixed-point number
#define FIXED_POINT_BITS 32

#define q 14
#define p 17

// Define a constant that represents the value 1 in fixed-point format
#define f (1 << q)

// Define a type alias named fixed_point to represent a fixed-point number
typedef int fixed_point;

// Function to convert an integer to its fixed-point representation
fixed_point int_to_fixed(int x) {
    return x * f; // Shift the integer left by FIXED_POINT_BITS bits
}

// Function to convert a fixed-point number to its integer representation
int fixed_to_int(fixed_point x) {
    if (x >= 0)
        // Round the fixed-point number to the nearest integer
        return (x + (f/2)) / f;
    else
        // Round the fixed-point number to the nearest integer
        return (x - (f/2)) / f;
}

// Function to perform addition on two fixed-point numbers
fixed_point fixed_add(fixed_point x, fixed_point y) {
    return x + y; // Add the two fixed-point numbers
}

// Function to perform subtraction on two fixed-point numbers
fixed_point fixed_subtract(fixed_point x, fixed_point y) {
    return x - y; // Subtract the second fixed-point number from the first one
}

fixed_point int_fixed_add(fixed_point x, int n)
{
    return x + (n * f);
}

fixed_point int_fixed_sub(fixed_point x, int n)
{
    return x - (n * f);
}

// Function to perform multiplication on two fixed-point numbers
fixed_point fixed_multiply(fixed_point x, fixed_point y) {
    // Multiply the two fixed-point numbers and divide the result by f to get the fixed-point representation
    return (((int64_t)x) * y) / f;
}

// Function to perform division on two fixed-point numbers
fixed_point fixed_divide(fixed_point x, fixed_point y) {
    // Multiply the first fixed-point number by f and divide the result by the second fixed-point number to get the fixed-point representation
    return (((int64_t)x) * f) / y;
}

fixed_point int_fixed_mul(fixed_point x, int n)
{
    return x * n;
}

fixed_point int_fixed_div(fixed_point x, int n)
{
    return x / n;
}
// End of the header guard
#endif //FIXED_POINT_H
