# Safety Algorithm

- The Safety Algorithm determines whether a state is safe if the system can allocate resources to each process in some order and still avoid a deadlock. 
- A system is in a safe state only if there exists a safe sequence.



## Algorithm

Step 1: Let Work and Finish be vectors of length *m* and *n*, respectively.
   Initialize:
   - Work = Available
   - Finish[i] = false for i = 0, 1, ..., n − 1

Step 2: Find an index *i* such that:
   - Finish[i] == false
   - Need[i] ≤ Work
   If no such *i* exists, go to step 4.

Step 3: Work = Work + Allocation[i]
   - Finish[i] = true
     Go to step 2.

Step 4: If Finish[i] == true for all *i*, then the system is in a safe state.

**Time Complexity:** O(m × n²)



