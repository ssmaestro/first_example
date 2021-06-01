#include <stdio.h>
#include <conio.h>
#define INFINITY 9999
void dijkstra(int[][10], int, int);
void main()
{
    int D[10][10], i, j, n, u;
    printf("Enter the number of nodes:");
    scanf("%d", &n);
    printf("\nNow enter the adjacency matrix:\n");
    printf("\nDo not enter a negative path distance\n");

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            printf("\nEnter the direct path distance between node %d and %d: ", i, j);
            scanf("%d", &D[i][j]);
        }
    }

    printf("\nEnter the starting node for the Dijksta's Algorithm to work :");
    scanf("%d", &u);
    dijkstra(D, n, u);
    getch();
}

void dijkstra(int D[10][10], int n, int startnode)
{

    int cost[10][10], distance[10], prev[10];
    int visited[10], count, mindistance, nextnode, i, j;

    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            if (D[i][j] == 0)
            {
                cost[i][j] = INFINITY;
            }
            else
            {
                cost[i][j] = D[i][j];
            }

    for (i = 0; i < n; i++)
    {
        distance[i] = cost[startnode][i];
        prev[i] = startnode;
        visited[i] = 0;
    }

    distance[startnode] = 0;
    visited[startnode] = 1;
    count = 1;

    while (count < n - 1)
    {
        mindistance = INFINITY;

        for (i = 0; i < n; i++)
        {
            if (distance[i] < mindistance && !visited[i])
            {
                mindistance = distance[i];
                nextnode = i;
            }
        }
        visited[nextnode] = 1;
        for (i = 0; i < n; i++)
        {
            if (!visited[i])
                if (mindistance + cost[nextnode][i] < distance[i])
                {
                    distance[i] = mindistance + cost[nextnode][i];
                    prev[i] = nextnode;
                }
        }
        count++;
    }

    for (i = 0; i < n; i++)
        if (i != startnode)
        {
            printf("\nDistance of node%d=%d", i, distance[i]);
            printf("\nPath=%d", i);

            j = i;
            do
            {
                j = prev[j];
                printf("<-%d", j);
            } while (j != startnode);
        }
}