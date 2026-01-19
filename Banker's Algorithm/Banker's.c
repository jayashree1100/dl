/* File : banker's.c
Purpose : Implements the Banker's Algorithm to check if the system is in a safe state

Description:
This file contains the main Banker's Algorithm, including functions to accept input matrices, print matrices, execute the banker() function,
and handle additional resource requests.
*/
#include <stdio.h>
#include <stdlib.h>

// n represents processes
// m represents resources

void print(int x[][10], int n, int m)
{
    int i, j;

    for (i = 0; i < n; i++)
    {
        printf("\n");

        for (j = 0; j < m; j++)
        {
            printf("%d\t", x[i][j]);
        }
    }
}

// Resource Request Algorithm
// A represents allocation matrix
// N represents need matrix
// AV represents available matrix

void res_request(int A[10][10], int N[10][10], int AV[10][10], int pid, int m)
{
    int reqmat[1][10];
    int i;

    printf("\n Enter additional request :- \n");

    for (i = 0; i < m; i++)
    {
        printf(" Request for resource %d : ", i);
        scanf("%d", &reqmat[0][i]);
    }

    // Requested matrix value is greater than need value, then error is encountered
    for (i = 0; i < m; i++)
    {
        if (reqmat[0][i] > N[pid][i])
        {
            printf("\n Error encountered.\n");
            exit(0);
        }
    }

    for (i = 0; i < m; i++)
    {
        // Updated available for process requested
        AV[0][i] -= reqmat[0][i];
        printf("available:%d\n", AV[0][i]);

        // Updated allocation for process requested
        A[pid][i] += reqmat[0][i];
        printf("allocation:%d\n", A[pid][i]);

        // Updated need for process requested
        N[pid][i] -= reqmat[0][i];
        printf("need:%d\n", N[pid][i]);
    }
}

// Safety Algorithm

int safety(int A[][10], int N[][10], int AV[10][10], int n, int m, int a[])
{
    int i, j, k, x = 0;

    // Work is initialize work and finish
    int F[10], W[1][10];
    int pflag = 0, flag = 0;

    for (i = 0; i < n; i++)
    {
        F[i] = 0;
    }

    // step1: Initialize work = available
    for (i = 0; i < m; i++)
    {
        W[0][i] = AV[0][i];
    }

    for (k = 0; k < n; k++)
    {
        for (i = 0; i < n; i++)
        {
            if (F[i] == 0)
            {
                flag = 0;

                for (j = 0; j < m; j++)
                {
                    // step2: If need > work, go to unsafe state
                    if (N[i][j] > W[0][j])
                    {
                        flag = 1;
                    }
                }

                // step3: If finish[i] == false and need <= work
                if (flag == 0 && F[i] == 0)
                {
