#include <stdio.h>
#include<stdlib.h>

void printPascalTriangle(long int n)
{
   long int no_row=n; 
   long long int c=1,blk,i,j;
   for(i=0;i<no_row;i++)
    {

        for(blk=1;blk<=no_row-i;blk++)   printf("  ");
        for(j=0;j<=i;j++)
        {
            if (j==0||i==0)
                c=1;
            else
               c=c*(i-j+1)/j;
            printf("% 4d",c);
         }
         printf("\n");
    }

}

void main(int argc, char *argv[])
{
    long int p;
    p=strtol(argv[1], NULL, 10);
    printPascalTriangle(p);
}
