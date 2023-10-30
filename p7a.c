#include <stdio.h>
#include <stdlib.h>
struct fileTable
{
   char name[20];
   int sb, nob;
} ft[30];
void main()
{
   int i, j, n;
   char s[20];
   printf("Enter the number of files: ");
   scanf("%d", &n);
   for (i = 0; i < n; i++)
   {
      printf("\nEnter %d filename -- ", i + 1);
      scanf("%s", ft[i].name);
      printf("\nEnter the starting block of the file %d -- ", i + 1);
      scanf("%d", &ft[i].sb);
      printf("\nEnter the number of blocks in the file %d -- ", i + 1);
      scanf("%d", &ft[i].nob);
   }
   printf("\nEnter the filename to be searched --");
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
      printf("\nFILE NAME\tSTART BLOCK\tNUMBER OF BLOCKS\tOCCUPIED\n");
      printf("\n%s\t%d\t\t\t\t%d\t", ft[i].name, ft[i].sb, ft[i].nob);
      for (j = 0; j < ft[i].nob; j++)
      {
         printf("%d,", ft[i].sb + j);
      }
      printf("\n");
   }
}
