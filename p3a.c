#include<stdio.h>
#include<stdlib.h>
void main()
{
  int buffer[10], bufsize, in, out, produce, consume, choice=0;
  in=0;out=0;bufsize=10;   
  while(choice!=3)
  {
    printf("\n1.Produce\n2.Consume\n3.Exit");
    printf("\nEnter your choice: ");
    scanf("%d",&choice);
    switch(choice)
    {
        case 1: if((in+1)%bufsize==out)
        {
            printf("Buffer Full\n");
        }
        else
        {
            printf("\nEnter value: ");
            scanf("%d",&produce);
            buffer[in]=produce;
            in=(in+1)%bufsize;
        }
        break;
        case 2: if(in==out)
        {
            printf("Buffer is empty\n");
        }
        else
        {
            consume=buffer[out];
            printf("\nThe consumed value is %d\n",consume);
            out=(out+1)%bufsize;
        }
        break;
        case 3: exit(0);
        default: printf("\nWrong choice!!\n");
    }
  }
}
