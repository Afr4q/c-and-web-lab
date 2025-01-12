#include <stdio.h>

void main()
{
    int n, i, j, e, a, b;
    printf("enter the number of vertices : ");
    scanf("%d", &n);
    int adj[10][10] = {0}, visited[10] = {0}, indegree[10] = {0};
    printf("enter the number of edges : ");
    scanf("%d", &e);
    for (i = 0; i < e; i++)
    {
        printf("Enter vertex 1 and vertex 2 : ");
        scanf("%d %d", &a, &b);
        adj[a][b] = 1;
        indegree[b]++;
    }
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            if (!indegree[j] && !visited[j])
            {
                break;
            }
        }
        if (j == n)
        {
            printf("\nRemaining Graph is cyclic !!!!");
            break;
        }
        else
        {
            printf("%d ", j);
            visited[j] = 1;
            for (int k = 0; k < n; k++)
            {
                if (adj[j][k])
                {
                    indegree[k]--;
                }
            }
        }
    }
}