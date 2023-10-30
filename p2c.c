#include <stdio.h>
int main()
{
    int p[20], bt[20], pri[20], wt[20], tat[20], i, j, n, temp;
    float wtavg, tatavg;
    printf("\n enter number of processes: ");
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        p[i] = i;
        printf("\n enter burst time and priority for the process %d: ", i);
        scanf("%d%d", &bt[i], &pri[i]);
    }
    for (i = 0; i < n; i++)
    {
        for (j = i + 1; j < n; j++)
        {
            if (pri[i] > pri[j])
            {
                temp = p[i];
                p[i] = p[j];
                p[j] = temp;

                temp = bt[i];
                bt[i] = bt[j];
                bt[j] = temp;

                temp = pri[i];
                pri[i] = pri[j];
                pri[j] = temp;
            }
        }
    }
    wt[0] = wtavg = 0;
    tat[0] = tatavg = bt[0];
    for (i = 1; i < n; i++)
    {
        wt[i] = wt[i - 1] + bt[i - 1];
        tat[i] = tat[i - 1] + bt[i];
        wtavg = wtavg + wt[i];
        tatavg = tatavg + tat[i];
    }
    printf("\n\tProcess\t Priority\t Burst time\t Waiting time\t Turnaround time\n");
    for (i = 0; i < n; i++)
    {
        printf("\n\tP%d\t\t %d\t\t %d\t\t %d\t\t %d", p[i], pri[i], bt[i], wt[i], tat[i]);
    }
    printf("\n Average waiting time=%f", wtavg / n);
    printf("\n Average turnaround time=%f\n", tatavg / n);
    return 0;
}
