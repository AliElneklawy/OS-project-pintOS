# Task 3: Multi-level Feedback Queue Scheduler

## Data Structures and Modifications

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
 
The advanced scheduler depends on the OS to calculate the priorities of the threads. This is achieved by the `load_avg`, `recent_cpu` and `nice` variables. 

`load_avg` is a weighted moving average of the amount of waiting threads in `ready_list` and the current thread if it is not idle. At first, it is initialized to zero. Then, it is updated every second according to the followin formula: $$load\textunderscore avg = \left(\frac{59}{60}\right) \times load\textunderscore  avg + \left(\frac{1}{60}\right) \times ready\textunderscore threads$$

`recent_cpu` is a variable that estimates how much time a thread spent using the cpu. Each time a timer interrupt occurs, `recent_cpu` is incremented by 1 for the running thread only. Its value is also recalculated every second for all threads according to the following formula:  $$recent\textunderscore cpu = \frac{2 \times load\textunderscore avg}{2 \times load\textunderscore avg + 1} \times recent\textunderscore cpu + nice$$ where `nice` is a variable set by the user and initially set to zero. The value of `nice` ranges from -20 to 20.

The `priority` varibale, declared inside `struct thread`, defines the priority of each thread. It is calculated every four ticks and every second through the following equation, $$priority = PRI\textunderscore MAX - \frac{recent\textunderscore cpu}{4} - (2 \times nice)$$ Preemption should occur if the resulting priority is greater than the priority of the current thread.

