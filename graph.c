#include <stdio.h>

int visiteddfs[10] = {0}, adj[10][10], parent[10];

void dfs(int start, int n)
{
    visiteddfs[start] = 1;
    printf("%d ", start);
    for (int i = 0; i < n; i++)
    {
        if (adj[start][i] != 0 && visiteddfs[i] == 0)
        {
            dfs(i, n);
        }
    }
}

void bfs(int start, int n)
{
    int q[10], front, rear;
    int e, visited[10] = {0};
    front = rear = 0;
    visited[start] = 1;
    q[front] = start;
    while (front <= rear)
    {
        int node = q[front++];
        printf("%d ", node);
        for (int i = 0; i < n; i++)
        {
            if (visited[i] == 0 && adj[node][i] != 0)
            {
                visited[i] = 1;
                q[++rear] = i;
            }
        }
    }
}

void prims(int start, int n)
{
    int e = 0, mst[10][10], visited[10] = {0}, min, adj1[n][n], mini, minj;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (adj[i][j] == 0)
            {
                adj1[i][j] = 999;
            }
            else
            {
                adj1[i][j] = adj[i][j];
            }
            mst[i][j] = 0;
        }
    }
    visited[start] = 1;
    while (e < n - 1)
    {
        min = 999;
        for (int i = 0; i < n; i++)
        {
            if (visited[i] == 1)
            {
                for (int j = 0; j < n; j++)
                {
                    if (visited[j] == 0 && adj1[i][j] < min)
                    {
                        min = adj1[i][j];
                        mini = i;
                        minj = j;
                    }
                }
            }
        }
        mst[mini][minj] = mst[minj][mini] = min;
        visited[minj] = 1;
        e++;
    }
    printf("___MST matrix___");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("%d ", mst[i][j]);
        }
        printf("\n");
    }
}

int find(int v)
{
    while (parent[v] != v)
    {
        v = parent[v];
    }
    return v;
}

void uni(int v1, int v2)
{
    parent[v2] = v1;
}

void kruskal(int n)
{
    int e = 0, mst[10][10]={0}, visited[10] = {0}, min, adj1[n][n], mini, minj;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (adj[i][j] == 0)
            {
                adj1[i][j] = 999;
            }
            else
            {
                adj1[i][j] = adj[i][j];
            }
            parent[i] = i;
        }
    }
    while (e < n - 1)
    {
        min = 999;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (adj1[i][j] < min && find(i) != find(j))
                {
                    min = adj1[i][j];
                    mini = i;
                    minj = j;
                }
            }
        }
        uni(mini, minj);
        mst[mini][minj] = mst[minj][mini] = min;
        adj1[mini][minj] = adj1[minj][mini] = 999;
        e++;
    }
    printf("___MST matrix___");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("%d ", mst[i][j]);
        }
        printf("\n");
    }
}