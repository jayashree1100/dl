/* File       : resource_req.c
   Purpose    : Implements the Resource Request Algorithm
   Author     : Jayashree

   Description:
     In this file contains the res_request() function which handles additional resource requests from a process and updates the Allocation, Need, and Available matrices accordingly.
*/

#include <stdio.h>
#include <stdlib.h>

// Resource Request Algorithm
// Parameters:
// A   - Allocation matrix
// N   - Need matrix
// AV  - Available resources
// pid - Process requesting additional resources
// m   - Number of resources
void res_request(int A[10][10], int N[10][10], int AV[10][10], int pid, int m)
{
    int reqmat[1][10];
    int i;

    printf("\nEnter additional resource request for process %d:\n", pid);

    // Accept request for each resource
    for (i = 0; i < m; i++)
    {
        printf(" Resource %d: ", i);
        scanf("%d", &reqmat[0][i]);
    }

    // Requested matrix value is greater than need value, then error is encountered
    for (i = 0; i < m; i++)
    {
        if (reqmat[0][i] > N[pid][i])
        {
            printf("\nError: Requested resources exceed process need.\n");
            exit(0);
        }
    }

    for (i = 0; i < m; i++)
    {
      // Updated available for process requested
        AV[0][i] -= reqmat[0][i];      
        printf("Available[%d]: %d\n", i, AV[0][i]);
      
      // Updated allocation for process requested
        A[pid][i] += reqmat[0][i];     
        printf("Allocation[%d]: %d\n", i, A[pid][i]);

      // Updated need for process requested
        N[pid][i] -= reqmat[0][i];    
        printf("Need[%d]: %d\n", i, N[pid][i]);
    }
}
