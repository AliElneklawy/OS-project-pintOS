# Task 3: Multi-level Feedback Queue Scheduler

## Data structures

1- In `thread.h`: 
  * Added two attributes to the thread struct.
    - `nice`: determines how nice the thread is.
    - `recent_cpu`: measures the amount of time the thread spent on using the cpu.
  
  ```c
  struct thread{
  
    ...
    int nice;     
    int recent_cpu;    
    ...
    
  };
  ```
 * Added a global variable `extern int load_avg` that estimates the average number of ready threads in the past minute.
 * Declared three functions:
   - `void calc_recent_cpu(struct thread *);`
   - `void calc_priority(struct thread *);`
   - `void calc_load_avg();`
  
2- In `thread.c`: 
 * Initialized the variables `nice`, `recent_cpu`, and `load_avg` to zero.

3- Added a header file `fixed_point.h` to handle fixed point operations.

## Algorithm
 
