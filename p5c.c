#include<stdio.h>

int fr[3], n, m;

void display() {
    printf("Current frames: ");
    for (int i = 0; i < m; i++) {
        if (fr[i] != -1) {
            printf("%d ", fr[i]);
        } else {
            printf("-1 "); 
        }
    }
    printf("\n");
}

void main()
{
    int i,j,page[20],fs[20];
    int max,found=0,lg[3],index,k,l,flag1=0,flag2=0,pf=0;    
    float pr;
    printf("Enter the length of the reference string: ");
    scanf("%d",&n);
    printf("Enter the reference string: ");
    for(i=0;i<n;i++)
    {
        scanf("%d",&page[i]);
    }
    printf("Enter the number of frames: ");
    scanf("%d",&m);
    
    for(i=0;i<m;i++)
    {
        fr[i]=-1;
        pf=m;   
    }
    for(j=0;j<n;j++)
    {
        flag1=0;
        flag2=0;
        for(i=0;i<m;i++)
        {
            if(fr[i]==page[j])
            {
                flag1=1;
                flag2=1;
                break;
            }
        }
        if(flag1==0)
        {
            for(i=0;i<m;i++)
            {
              if(fr[i]==-1)
              {
                fr[i]=page[j];
                flag2=1;
                break;
              }   
            }
        }
        if(flag2==0)
        {
            for(i=0;i<m;i++)
            {
                lg[i]=0;
            }
            for(i=0;i<m;i++)
            {
                for(k=j+1;k<n;k++)
                {
                    if(fr[i]==page[k])
                    {
                        lg[i]=k-j;
                        break;
                    }
                } 
            }
            found=0;
            for(i=0;i<m;i++)
            {
                if(lg[i]==0)
                {
                    index=i;
                    found=1;
                    break;
                }
            }
            if(found==0)
            {
                max=lg[0];
                index=0;
                for(i=0;i<m;i++)
                {
                    if(max<lg[i])
                    {
                       max=lg[i];
                       index=i; 
                    }
                }
            }
            fr[index]=page[j];
            pf++;
        }
        display();
    }
   printf("Number of page faults using optimal are: %d\n",pf);
   pr=(float)pf/n*100; 
   printf("Page fault rate is: %f\n",pr);
}




