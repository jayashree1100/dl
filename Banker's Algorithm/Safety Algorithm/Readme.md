# Safety Algorithm
<img src="https://github.com/jayashree1100/Deadlock/blob/main/Banker's%20Algorithm/images/safe.png" alt="Safe State Diagram" align="right" width="110" height="110" style="margin-left:20px; margin-bottom:0; margin-top:0;">

A system is in a **safe state** if it can allocate resources to each process in some order and still avoid a deadlock. A system is in a safe state only if there exists a safe sequence of processes where each process can obtain all resources it may request and complete.
  - If a system is in safe state => no deadlocks
  - If a system is in unsafe state => possibility of deadlock
  - Avoidance => ensure that a system will never enter an unsafe state

All resource requests are analyzed before allocation to ensure the system remains in a safe state.

This image shows a system in safe, unsafe, and deadlocked states, clearly indicating which sequences allow processes to complete safely.



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



