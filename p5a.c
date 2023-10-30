#include <stdio.h>
void main()
{
    int i, j, k, f, pf = 0, cnt = 0, rs[25], m[10], n;

    printf("\nEnter the length of the reference string: ");
    scanf("%d", &n);
    printf("\nEnter the reference string: ");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &rs[i]);
    }
    printf("\nEnter the number of frames: ");
    scanf("%d", &f);
    for (i = 0; i < f; i++)
    {
        m[i] = -1;
    }
    printf("\nPage replacement process is:\n");

    for (i = 0; i < n; i++)
    {
        for (k = 0; k < f; k++)
        {
            if (m[k] == rs[i])
                break;
        }
        if (k == f)
        {
            m[cnt++] = rs[i];
            pf++;
        }
        for (j = 0; j < f; j++)
        {
            printf("%d\t", m[j]);
        }
        if(k==f)
        {
        printf("\t PF no. %d",pf);
        }
        printf("\n");
        if(cnt==f)
        {
        cnt=0;
        }
    }
    printf("\nThe number of Page Faults using FIFO is: %d\n", pf);
}
