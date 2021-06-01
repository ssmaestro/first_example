#include <stdio.h>
#include <conio.h>
void knapsack(int, float[], float[], float);
void main()
{
    int cap, i, j, n;
    float weight[10], profit[10], fraction[10], temp;
    printf("\nEnter the no. of items available for knapsack:-");
    scanf("%d", &n);
    printf("\nEnter the maximum capacity of knapsack:-");
    scanf("%d", &cap);
    printf("\nNow enter the profits and weights of the items:\n");
    for (i = 0; i < n; i++)
    {
        scanf(" %f   %f", &profit[i], &weight[i]);
        printf("\n");
        fraction[i] = profit[i] / weight[i];
    }
    
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n-i-1; j++)
        {
            if (fraction[j] < fraction[j + 1])
            {
                temp = fraction[j];
                fraction[j] = fraction[j + 1];
                fraction[j + 1] = temp;

                temp = weight[j];
                weight[j] = weight[j + 1];
                weight[j + 1] = temp;

                temp = profit[j];
                profit[j] = profit[j + 1];
                profit[j + 1] = temp;
            }
        }
    }
    for (i = 0; i < n; i++)
    {
        printf("\nThe number %d object has %f weight and %f profit\n", (i + 1), weight[i], profit[i]);
    }
    knapsack(n, weight, profit, cap);
    getch();
}

void knapsack(int n, float weight[], float profit[], float cap)
{
    int i;
    int u = cap;
    float max_profit = 0.0;
    float arr[10];
    for (i = 0; i < n; i++)
    {
        arr[i] = 0;
    }
    for (i = 0; i < n; i++)
    {
        if (weight[i] > u)
        {
            break;
        }
        else
        {
            arr[i] = 1.0;
            max_profit = max_profit + profit[i];
            u = u - weight[i];
        }
    }
    if (i < n)
    {
        arr[i] = u / weight[i];
    }
    max_profit = max_profit + (arr[i] * profit[i]);
    printf("\n\n");
     for (i = 0; i < n; i++)
    {
        printf("\nThe fraction of object taken to achieve maximum profit for number %d object is %f", (i+1), arr[i]);
    }
    printf("\n\nThe maximum profit that can be obtained in the given knapsack is:- %f", max_profit);
    
}
