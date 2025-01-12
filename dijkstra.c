#include <stdio.h>

int visited[10] = {0}, distance[10] = {__INT_MAX__}, adj[10][10];

int findMin(int n)
{
    int min = __INT_MAX__, minindex;
    for (int i = 0; i < n; i++)
    {
        if (visited[i] <= min && visited[i] == 0)
        {
            min = distance[i];
            minindex = i;
        }
    }
    return minindex;
}

void dijkstra(int n,int source)
{
    distance[source]=0;
    for (int i = 0; i < n; i++)
    {
        int u = findMin(n);
        visited[u]=1;
        for (int v = 0; v < n; v++)
        {
            if (!visited[v] && adj[u][v] && distance[u] != __INT_MAX__ && distance[u] + adj[u][v] < distance[v])
            {
                distance[v] = distance[u] + adj[u][v];
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        printf("%d\t\t\t%d",i,distance[i]);
    }
}