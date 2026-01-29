# Deadlock Detection Algorithm

If a system does not employ either a deadlock-prevention or a deadlock-avoidance algorithm, then a deadlock situation may occur. In this environment, the system may provide:
  - An algorithm that examines the state of the system to determine whether a deadlock has occurred
  - An algorithm to recover from the deadlock

Detection Algorithm is used to examine the system state and identify whether a deadlock has occurred and which processes are involved.

## Algorithm

Step 1: Let Work and Finish be vectors of length m and n, respectively.
   Initialize:
   - Work = Available
   - For i = 0, 1, ..., n − 1:
     - If Allocation[i] = 0, then Finish[i] = false
     - Otherwise, Finish[i] = true

Step 2: Find an index i such that:
   - Finish[i] == false
   - Request[i] ≤ Work
   If no such i exists, go to step 4.

Step 3: Work = Work + Allocation[i]
   - Finish[i] = true
     Go to step 2.

Step 4: If Finish[i] == false for some i, 0 ≤ i < n, then the system is in a deadlocked state.
   Moreover, if Finish[i] == false, then process Pi is deadlocked.

**Time Complexity:** O(m × n²)
