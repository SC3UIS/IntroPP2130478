/*

  Purpose:

    omp_PascalTriangle is a code that allow display a pascal's trinagle given the numbers of rows of such triangle.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    24 November 2020

  Author:
  w3resource
  OpenMP Modification:
  24 November 2020 by Jorge Perea, Universidad Industrial de Santander bassbeat120@hotmail.com
  This OpenMP Modification makes a parallelization of the original Code i.e. this modification parallelize the 3 for loops of the original code.Every for loop results is sequentially ordered after running in parallel.
*/
#include <stdio.h>
#include <omp.h>
void main()
{
   int no_row=15,c=1,blk,i,j;   /*the pascal triangle will have 15 rows*/
  
   /*main for loop parallelization*/
   #pragma omp parallel for ordered
   for(i=0;i<no_row;i++)
    {
        #pragma omp ordered

       /*first for loop parallelization*/
        #pragma omp parallel for ordered
        for(blk=1;blk<=no_row-i;blk++)
        #pragma omp ordered
        printf("  ");
       /*first for loop parallelization*/

       /*second for loop parallelization*/
        #pragma omp parallel for ordered
        for(j=0;j<=i;j++)
         {
            #pragma omp ordered
            if (j==0||i==0)
                c=1;
            else
               c=c*(i-j+1)/j;
            printf("% 4d",c);
         }
       /*second for loop parallelization*/

        printf("\n");
    }
    /*main for loop parallelization*/

}
