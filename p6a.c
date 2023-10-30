#include<stdio.h>
#include<stdlib.h>
int main()
{
    int queue[20], n, head, i, j, seek = 0, max, diff;
    float avg;
    printf("Enter the size of queue requests:\n");
    scanf("%d", &n);
    printf("Enter the queue of disk positions to be read:\n");
    for (i = 1; i <= n; i++)
    {
        scanf("%d", &queue[i]);
    }
    printf("Enter the initial head position:\n");
    scanf("%d", &head);
    queue[0] = head;
    for (j = 1; j <= n; j++) 
    {
        diff = abs(queue[j] - queue[j - 1]); 
        seek += diff;
        printf("Disk head moves from %d to %d with seek %d\n", queue[j - 1], queue[j], diff);
    }
    printf("Total seek time is %d\n", seek);
    avg = (float)seek / n;
    printf("Average seek time is %f\n", avg);
    return 0;
}
