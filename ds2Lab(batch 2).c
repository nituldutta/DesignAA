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
 
#define V 6
int minDistance(int dist[], bool sptSet[])
{
 
    int min = INT_MAX, min_index;
 
    for (int v = 0; v < V; v++)
        if (sptSet[v] == false && dist[v] <= min)
            min = dist[v], min_index = v;
 
    return min_index;
}
 
// A utility function to print the constructed distance array
int printSolution(int dist[], int n)
{
    printf("Vertex   Distance from Source\n");
    for (int i = 0; i < V; i++)
        printf("%d \t\t %d\n", i, dist[i]);
return 0;}
void dijkstra(int graph[V][V], int src)
{
    int dist[V]; // The output array.  dist[i] will hold the shorte
    bool sptSet[V]; // sptSet[i] will be true if vertex i is included in shortest
    for (int i = 0; i < V; i++)
        dist[i] = INT_MAX, sptSet[i] = false;
    dist[src] = 0;
    for (int count = 0; count < V - 1; count++) {
        int u = minDistance(dist, sptSet);
        sptSet[u] = true;
        for (int v = 0; v < V; v++)
            if (!sptSet[v] && graph[u][v] && dist[u] != INT_MAX
                && dist[u] + graph[u][v] < dist[v])
                dist[v] = dist[u] + graph[u][v];
    }
    printSolution(dist, V);
}
int main()
{
    int graph[V][V] = { { 0, 4, 0, 0, 0, 0},
                        { 4, 0, 8, 0, 0, 0},
                        { 0, 8, 0, 7, 0, 4},
                        { 0, 0, 7, 0, 9, 14},
                        { 0, 0, 0, 9, 0, 10},
                        { 0, 0, 4, 14,10, 0},
                       };
                        
    dijkstra(graph, 0);
 
    return 0;
}
