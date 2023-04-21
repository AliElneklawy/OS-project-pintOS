# Task 3: Multi-level Feedback Queue Scheduler

## Data structures

1- In `thread.h`: 
  * Added to attributes to the thread struct.
    - `nice`: determines how nice the thread is.
    - `recent_cpu`: measures the amount of time the thread spent on using the cpu.
  
  ```
  struct thread{
  
    ...
    int nice;     
    int recent_cpu;    
    ...
    
  };
  ```
 * Added a global variable `extern int load_avg` that estimates the average number of ready threads in the past minute.
  
2- In `thread.c`: 
