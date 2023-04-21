# Task 3: Multi-level Feedback Queue Scheduler

## ** Data structures **

1- In `thread.h`: added to attributes.
  ```
  struct thread{
  
    ...
    int nice;     
    int recent_cpu;    
    ...
    
  };
  
  ```
