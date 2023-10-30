#include <stdio.h>
int main()
{
    int bt[10], wt[10], tat[10], i, j, n, t, ct[10], max;
    float awt=0, att=0, temp=0;
    printf("\nEnter number of processes: ");
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        printf("\nEnter burst time for the process %d: ", i);
        scanf("%d", &bt[i]);
        ct[i]=bt[i];
    }
    printf("\nEnter the time slice: ");
    scanf("%d", &t);
    max = bt[0];
    for (i = 1; i < n; i++)
    {
        if (max < bt[i])
        {
            max = bt[i];
        }
    }
    for (j = 0; j < (max / t) + 1; j++)
    {
        for (i = 0; i < n; i++)
        {
            if (bt[i] != 0)
            {
                if (bt[i] <= t)
                {
                    tat[i] = temp + bt[i];
                    temp = temp + bt[i];
                    bt[i] = 0;
                }
                else
                {
                    bt[i] = bt[i] - t;
                    temp = temp + t;
                }
            }
        }
    }
    for (i = 0; i < n; i++)
    {
        wt[i] = tat[i] - ct[i];
        att += tat[i];
        awt += wt[i];
    }
    printf("\n\tProcess\t  Burst time\t Waiting time\t Turnaround time\n");
    for (i = 0; i < n; i++)
    {
        printf("\n\tP%d\t\t %d\t\t %d\t\t %d", i + 1, ct[i], wt[i], tat[i]);
    }
    
    printf("\n Average turnaround time=%f\n", att / n);
    printf("\n Average waiting time=%f\n", awt / n);
    return 0;
}
