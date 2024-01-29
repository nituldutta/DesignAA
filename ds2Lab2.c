/*
input matrix (graph)
        graph[6][6] = { { 0, 4, 0, 0, 0, 0},
                        { 4, 0, 8, 0, 0, 0},
                        { 0, 8, 0, 7, 0, 4},
                        { 0, 0, 7, 0, 9, 14},
                        { 0, 0, 0, 9, 0, 10},
                        { 0, 0, 4, 14,10, 0},
                       };

Vertex   Distance from Source
0                0
1                4
2                12
3                19
4                26
5                16
*/
#include <limits.h>
#include <stdio.h>
#include <stdbool.h> 
#define I 6
int mD(int d[], bool sS[])
{
    int min = 9999, mi;
     for (int i = 0; i < I; i++)
        if (sS[i] == false && d[i] <= min)
            min = d[i], mi = i;
    return mi;
}
 
int printSolution(int d[], int n)
{
    printf("Results. \n");
    for (int i = 0; i < I; i++)
        printf("%d \t\t %d\n", i, d[i]);
return 0;}
void dk(int A[I][I], int s)
{
    int d[I]; 
    bool sS[I]; 
    for (int i = 0; i < I; i++)
        d[i] = 9999, sS[i] = false;
    d[s] = 0;
    for (int count = 0; count < I - 1; count++) {
        int k = mD(d, sS);
        sS[k] = true;
        for (int l = 0; l < I; l++)
            if (!sS[l] && A[k][l] && d[k] != INT_MAX
                && d[k] + A[k][l] < d[l])
                d[l] = d[k] + A[k][l];
    }
    printSolution(d, I);
}
int main()
{
int A[I][I] = {0, 4, 0, 0, 0, 0, 4, 0, 8, 0, 0, 0,0, 8, 0, 7, 0, 4,0, 0, 7, 0, 9, 14,0, 0, 0, 9, 0, 10,0, 0, 4, 14,10, 0,};                     
dk(A, 0);
return 0;
}
