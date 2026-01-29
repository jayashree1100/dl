# Deadlock Avoidance and Detection Algorithms – Operating Systems

## Project Objective
- Develop a code of **deadlocks**, which prevent sets of concurrent processes from completing their tasks.
- Present a number of different methods for **preventing or avoiding deadlocks** in a computer system.

## Deadlock
A process requests resources; if the resources are not available at that time, the process enters a waiting state. Sometimes, a waiting process is never again able to change state, because the resources it has requested are held by other waiting processes. This situation is called a **deadlock**.

A deadlock can occur **if and only if** all four conditions hold simultaneously:
1. **Mutual Exclusion:** At least one resource cannot be shared.
2. **Hold & Wait:** Processes hold resources while requesting additional ones.
3. **No Preemption:** Resources cannot be forcibly taken from a process.
4. **Circular Wait:** There is a cycle of processes where each waits for a resource held by the next.
These are the four necessary conditions for deadlock.

## Graph-Based Representation of Deadlocks

### Resource Allocation Graph (RAG)
<img src="https://github.com/jayashree1100/dl/blob/9afe2035800f4d0556532a7c09dcd792a3a63d2e/Banker's%20Algorithm/images/RAG%20ND.jpg" alt="Safe State Diagram" align="right" width="110" height="110" style="margin-left:20px; margin-bottom:0; margin-top:0;"><img src="https://github.com/jayashree1100/dl/blob/9afe2035800f4d0556532a7c09dcd792a3a63d2e/Banker's%20Algorithm/images/RAG%20WD.jpg" alt="Safe State Diagram" align="right" width="110" height="110" style="margin-left:20px; margin-bottom:0; margin-top:0;">A **Resource Allocation Graph** represents processes and resources as nodes and the allocation/request relationships as edges.
- A **request edge** (`Pi → Rj`) indicates that process Pi has requested an instance of resource Rj.
- An **assignment edge** (`Rj → Pi`) indicates that resource Rj is currently allocated to process Pi.

If no cycle exists in the graph, the system is free from deadlocks. If a cycle exists (for a single instance of each resource type), it indicates a deadlock.
Figure: Resource Allocation Graph showing process–resource relationships with and without a cycle.


### Wait‑For Graph
<img src="https://github.com/jayashree1100/dl/blob/9afe2035800f4d0556532a7c09dcd792a3a63d2e/Banker's%20Algorithm/images/WFG.JPG" align="right" width="190" height="190" style="margin-left:20px; margin-bottom:0; margin-top:0;"> The **Wait‑For Graph** simplifies the Resource Allocation Graph by removing resource nodes and showing only the waiting relationships between processes.
- In a Wait‑For Graph, a directed edge `Pi → Pj` means that *process Pi is waiting for a resource held by process Pj*. A cycle in the Wait‑For Graph implies a deadlock among the processes.
Figure: Wait‑For Graph showing waiting relationships among processes.


## Methods for Handling Deadlocks

### Deadlock Prevention
Deadlock prevention ensures that at least one of the necessary conditions for deadlock does not hold:
- Disallow **hold & wait** by requiring all resources to be requested at once.
- Enable **preemption** where resources can be taken from a process.
- Impose **resource ordering** to prevent circular wait.

### Deadlock Avoidance
Deadlock avoidance ensures that the system **never enters an unsafe state**.
- For systems with a **single instance** of each resource type, use the Resource Allocation Graph method.
- For systems with **multiple instances** of each resource, use the **Banker’s Algorithm**.

## Banker’s Algorithm
The **Banker’s Algorithm** is a deadlock avoidance algorithm that applies to systems with multiple instances of each resource type. Each process must declare its **maximum resource requirements** in advance. Resource requests are granted only if the system remains in a **safe state** after allocation.

The Banker’s Algorithm consists of two parts:
- **Safety Algorithm**
- **Resource‑Request Algorithm**

Limitations:
- Low device utilization.
- Reduced system throughput.


### Deadlock Detection Algorithm
If a system does not employ either a deadlock‑prevention or a deadlock avoidance algorithm, then a deadlock situation may occur. In this environment, the system may provide:

• An algorithm that examines the state of the system to determine whether a deadlock has occurred
• An algorithm to recover from the deadlock

## Implementation & Algorithms
- Developed modular **C programs** to simulate deadlock scenarios.
- Implemented and tested the following algorithms:

1. [Banker’s Algorithm](https://github.com/jayashree1100/dl/tree/9afe2035800f4d0556532a7c09dcd792a3a63d2e/Banker's%20Algorithm)
2. [Deadlock Detection Algorithm](https://github.com/jayashree1100/Deadlock/blob/8fc5b826cd3e65dd2090e543268c2652a48e5c24/Detection%20Algorithm)

- Programs simulate multiple processes and resource request/release sequences.
- Outputs indicate **safe, unsafe, and deadlocked states**, validating theoretical concepts.

## Key Skills & Learning Outcomes
- Applied techniques for **avoiding and detecting deadlocks**.
- Distinguished **safe vs unsafe system states** in resource allocation.
- Practiced **process coordination and resource management** in concurrent systems.


## Project Nature
This project was completed as a **semester mini project** for the Operating Systems course, focusing on practical implementation of deadlock avoidance and detection algorithms.

## Reference
Silberschatz, Abraham, Peter B. Galvin, and Greg Gagne. *Operating System Concepts*, Ninth edition, John Wiley & Sons, 2012.

## Copyright & Attribution
This project is developed for **educational purposes**. Content and descriptions are referenced from *Operating System Concepts* (Silberschatz, Galvin & Gagne, 9th Edition). All rights to the textbook belong to the original authors and publisher. This repository does not include copyrighted material beyond brief educational explanations.
