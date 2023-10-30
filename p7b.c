#include <stdio.h>
struct fileTable
{
    char name[20];
    int nob, blocks[30];
} ft[30];
void main()
{
    int i, j, n;
    char s[20];
    printf("Enter the number of files:");
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        printf("\nEnter the name %d -- ", i + 1);
        scanf("%s", ft[i].name);
        printf("\nEnter the number of blocks in the file %d-- ", i + 1);
        scanf("%d", &ft[i].nob);
        printf("\nEnter the blocks of the file --  ");
        for (j = 0; j < ft[i].nob; j++)
        {
            scanf("%d", &ft[i].blocks[j]);
        }
    }
    printf("\nEnter the file name to be searched -- ");
    scanf("%s", s);
    for (i = 0; i < n; i++)
    {
        if (strcmp(s, ft[i].name) == 0)
        {
            break;
        }
    }
    if (i == n)
    {
        printf("\nFile not found\n");
    }
    else
    {
        printf("\nFILE NAME NO OF BLOCKS BLOCKS OCCUPIED\n");
        printf("\n%s\t\t%d\t", ft[i].name, ft[i].nob);
        for (j = 0; j < ft[i].nob; j++)
        {
            printf("%d,", ft[i].blocks[j]);
        }
        printf("\n");
    }
}
