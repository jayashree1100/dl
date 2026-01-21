# Resource Request Algorithm (C)

  The Resource Request Algorithm determines whether a process can request additional resources without causing the system to enter an unsafe state.

---

## Algorithm

Let Requestᵢ be the request vector for process Pᵢ.

Step 1: If Requestᵢ ≤ Needᵢ, go to step 2.
Otherwise, raise an error condition.

Step 2: If Requestᵢ ≤ Available, go to step 3.
Otherwise, the process must wait.

Step 3: Pretend to allocate the requested resources:
- Available = Available − Requestᵢ
- Allocationᵢ = Allocationᵢ + Requestᵢ
- Needᵢ = Needᵢ − Requestᵢ

Step 4: Run the Safety Algorithm:
- If resulting state is safe → grant request
- If unsafe → restore old state and process waits

**Time Complexity:** O(m × n²)
