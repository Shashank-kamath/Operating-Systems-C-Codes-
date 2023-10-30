#include<stdio.h>
int main()
{
    int t[20],d[20],h,j,i,n,temp,k,atr[20],p,sum=0;
    printf("Enter the number of tracks to be traversed: ");
    scanf("%d",&n);
    printf("Enter the position of the head: ");
    scanf("%d",&h);
    t[0]=0;
    t[1]=h;
    printf("Enter the tracks:\n");
    for(i=2;i<n+2;i++)
    {
        scanf("%d",&t[i]);
    }
    for(i=0;i<(n+2);i++)
    {
        for(j=0;j<(n+2)-i-1;j++)
        {
            if(t[j]>t[j+1])
            {
                temp=t[j];
                t[j]=t[j+1];
                t[j+1]=temp;
            }
        }
    }

    for(i=0;i<(n+2);i++)
    {
        if(t[i]==h)
        {
            j=i;
            k=i;
            break;
        }
    }
    p=0;
    while(t[j]!=0)
    {
        atr[p]=t[j];
        j--;
        p++;
    }
    atr[p]=t[j];
    for(p=k+1;p<(n+2);p++,k++)
    {
        atr[p]=t[k+1];
    }
    printf("\nTracks traversed\t Difference between tracks\n");
    for(i=1;i<(n+2);i++)
    {
        if(atr[i]>atr[i-1])
        {
            d[i]=atr[i]-atr[i-1];
        }
        else
        {
            d[i]=atr[i-1]-atr[i];
        }
        printf("%d\t\t\t\t%d\n",atr[i],d[i]);
        sum+=d[i];
    }
    printf("\nTotal seek time is %d\n",sum);
    float avg=(float)sum/n;
    printf("Average header movements:%f\n",avg);
}