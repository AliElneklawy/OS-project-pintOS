# Task 3: Multi-level Feedback Queue Scheduler 

## Data Structures and Modifications

1- In `thread.h`: 
  * Added two attributes to the thread struct.
    - `nice`: determines how nice the thread is. The nicer the thread, the less priority it has.
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

The `priority` varibale, declared inside `struct thread`, defines the priority of each thread. It is calculated every four ticks and every second through the following equation, $$priority = PRI\textunderscore MAX - \frac{recent\textunderscore cpu}{4} - (2 \times nice)$$ where PRI_MAX equals 63. Preemption should occur if the resulting priority is greater than the priority of the current thread.


Assuming that the value of the time slice (time quantum) is 4 timer ticks, we can calculate the scheduling decision and the new priority and recent_cpu values for each thread after each given number of timer ticks as follows:

| timer ticks | recent_cpu A B C | priority A B C | thread to run |
| ----------- |-------------------|----------------|------------- |
| 0           | 0 0 0             | 63 61 59       | A             |
| 4           | 4 0 0             | 63 61 59       | A             |
| 8           | 8 4 0             | 62 61 59       | B             |
| 12          | 8 8 0             | 61 61 59       | B             |
| 16          | 8 8 4             | 61 60 59       | C             |
| 20          | 12 8 4            | 61 60 58       | A             |
| 24          | 16 8 4            | 60 60 58       | A             |
| 28          | 16 12 4           | 60 59 58       | B             |
| 32          | 16 16 4           | 59 59 58       | B             |
| 36          | 16 16 8           | 59 58 58       | C             |



## Did any ambiguities in the scheduler specification make values in the table uncertain ?
No ambiguity found since our implementation follows the spec perfectly.

## How is the way you divided the cost of scheduling between code inside and outside interrupt context likely to affect performance?

Dividing the cost of scheduling between code inside and outside interrupt context is important for performance because it reduces the amount of time spent in interrupt context, which is a time-critical section of code. If too much time is spent in interrupt context, it might result in slightly higher overheads due to increased context switches when moving from IRQ to User mode. However, this should be minimized since we set the irq_count field correctly during scheduling. Overall, our approach shouldn't lead to significant perf issues if implemented correctly.


| Cost | Inside interrupt context | Outside interrupt context |
|---|---|---|
| Time | Longer | Shorter |
| Interrupts generated | More | Fewer |
| Performance | Worse | Better |

