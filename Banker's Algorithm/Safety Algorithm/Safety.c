/* File       : Safety.c
   Purpose    : Implements the Safety Algorithm
   Author     : Jayashree

   Description:
     In this file contains the safety() function which checks whether the system is in a safe state and calculates a safe sequence of processes if one exists.
*/

#include <stdio.h>
#include <stdlib.h>

// Safety Algorithm
// Checks if the system is in a safe state and returns the safe sequence
int safety(int A[][10], int N[][10], int AV[10][10], int n, int m, int a[])
{
    int i, j, k, x = 0;
    int F[10], W[1][10]; // Finish flags and work array
    int pflag = 0, flag = 0;

    // Initialize finish flags to false
    for (i = 0; i < n; i++)
        F[i] = 0;

    // Step 1: Initialize work = available resources
    for (i = 0; i < m; i++)
        W[0][i] = AV[0][i];

    // Find processes that can proceed
    for (k = 0; k < n; k++)
    {
        for (i = 0; i < n; i++)
        {
            if (F[i] == 0)
            {
                flag = 0;
                for (j = 0; j < m; j++)
                 // step2: If need > work, go to unsafe state
                    if (N[i][j] > W[0][j])
                        flag = 1;

                // step3: if finish[i] == false and need <= work
                if (flag == 0 && F[i] == 0)
                {
                    for (j = 0; j < m; j++)
                      // update work = work + allocation
                        W[0][j] += A[i][j]; 

                    F[i] = 1;       // finish[i] = true
                    pflag++;
                    a[x++] = i;
                }
            }
        }
    }

    // Step 4: Check if all processes could finish
    if (pflag == n)
        return 1; // Safe state

    return 0; // Unsafe state
}
