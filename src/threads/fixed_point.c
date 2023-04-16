#ifndef FIXED_POINT_H
#define FIXED_POINT_H

#include <stdint.h>

// Define the number of bits used to represent the decimal portion of the fixed-point number
#define FIXED_POINT_BITS 16

// Define a constant that represents the value 1 in fixed-point format
#define FIXED_POINT_ONE (1 << FIXED_POINT_BITS)

// Define a type alias named fixed_point to represent a fixed-point number
typedef int fixed_point;

// Function to convert an integer to its fixed-point representation
fixed_point int_to_fixed(int x) {
    return x << FIXED_POINT_BITS; // Shift the integer left by FIXED_POINT_BITS bits
}

// Function to convert a fixed-point number to its integer representation
int fixed_to_int(fixed_point x) {
    // if (x >= 0)
    //     // Round the fixed-point number to the nearest integer
    //     return (x + ((FIXED_POINT_ONE / 2) / (FIXED_POINT_ONE)));
    // else
    //     // Round the fixed-point number to the nearest integer
    //     return (x - ((FIXED_POINT_ONE / 2) / (FIXED_POINT_ONE)));
    return x >>FIXED_POINT_BITS ;
}

// Function to perform addition on two fixed-point numbers
fixed_point fixed_add(fixed_point x, fixed_point y) {
    return x + y; // Add the two fixed-point numbers
}

// Function to perform subtraction on two fixed-point numbers
fixed_point fixed_subtract(fixed_point x, fixed_point y) {
    return x - y; // Subtract the second fixed-point number from the first one
}

// Function to perform multiplication on two fixed-point numbers
fixed_point fixed_multiply(fixed_point x, fixed_point y) {
    // Multiply the two fixed-point numbers and divide the result by FIXED_POINT_ONE to get the fixed-point representation
    return ((fixed_point)(((int64_t)x * y) / FIXED_POINT_ONE));
}

// Function to perform division on two fixed-point numbers
fixed_point fixed_divide(fixed_point x, fixed_point y) {
    // Multiply the first fixed-point number by FIXED_POINT_ONE and divide the result by the second fixed-point number to get the fixed-point representation
    return ((fixed_point)(((int64_t)x * FIXED_POINT_ONE) / y));
}

// End of the header guard
#endif //FIXED_POINT_H
