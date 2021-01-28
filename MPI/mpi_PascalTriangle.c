/*
  Purpose:
    mpi_PascalTriangle is a code that allow display a pascal's trinagle given the numbers of rows of such triangle.
  Licensing:
    This code is distributed under the GNU LGPL license.
  Modified:
     January 2021
  Author:
  w3resource
  MPI Modification:
  January 2021 by Jorge Perea, Universidad Industrial de Santander bassbeat120@hotmail.com
  This MPI Modification makes a parallelization of the original Code i.e. this modification use 3 process to compute the n rows of a pascal triangle. Roughly speaking each process computes n/3 rows.  
*/

#include <stdio.h>
#include <mpi.h>
#include<stdlib.h>
#define master 0
#define worker_1 1
#define worker_2 2
#define worker_3 3

void compute_rows(long int start,long int end,long int n_rows){
   long int i,blk,j,c=1;
   for(i=start;i<end;i++)
     {
        for(blk=1;blk<=n_rows-i;blk++) printf("  ");
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
  
   long int no_row,extra_rows;
   int id_proceso,from_worker_1,from_worker_2,from_worker_3;
   no_row=strtol(argv[1], NULL, 10);
   long int to_worker_1[]={0,0,no_row},to_worker_2[]={0,0,no_row},to_worker_3[]={0,0,no_row};
   MPI_Status status;
    
   MPI_Init(&argc, &argv);
   MPI_Comm_rank(MPI_COMM_WORLD, &id_proceso);
   if(id_proceso==master){
         extra_rows=no_row%3;
         switch(extra_rows){
             case 0:
                 to_worker_1[0]=0;
                 to_worker_1[1]=(no_row/3);
                 to_worker_2[0]=no_row/3;
                 to_worker_2[1]=(2*(no_row/3));
                 to_worker_3[0]=2*(no_row/3);
                 to_worker_3[1]=no_row;
                 break;
             case 1:
                 no_row=no_row-1;                
                 to_worker_1[0]=0;
                 to_worker_1[1]=(no_row/3);             
                 to_worker_2[0]=no_row/3;
                 to_worker_2[1]=(2*(no_row/3));             
                 to_worker_3[0]=2*(no_row/3);
                 to_worker_3[1]=no_row+1;
                 break;
             case 2:
                 no_row=no_row-2;
                 to_worker_1[0]=0;
                 to_worker_1[1]=(no_row/3);             
                 to_worker_2[0]=no_row/3;
                 to_worker_2[1]=(2*(no_row/3));             
                 to_worker_3[0]=2*(no_row/3);
                 to_worker_3[1]=no_row+2;  
                 break;
         }
         MPI_Send(&to_worker_1, 3, MPI_LONG_INT, worker_1, 0, MPI_COMM_WORLD);
         MPI_Recv(&from_worker_1, 1, MPI_INT, worker_1, 0, MPI_COMM_WORLD, &status);
       
         MPI_Send(&to_worker_2, 3, MPI_LONG_INT, worker_2, 0, MPI_COMM_WORLD);
         MPI_Recv(&from_worker_2, 1, MPI_INT, worker_2, 0, MPI_COMM_WORLD, &status);
       
         MPI_Send(&to_worker_3, 3, MPI_LONG_INT, worker_3, 0, MPI_COMM_WORLD);
         MPI_Recv(&from_worker_3, 1, MPI_INT, worker_3, 0, MPI_COMM_WORLD, &status);
       
   }else{
        switch(id_proceso){
             case worker_1:
                 MPI_Recv(&to_worker_1, 3, MPI_LONG_INT, master, 0, MPI_COMM_WORLD, &status);
                 compute_rows(to_worker_1[0],to_worker_1[1],to_worker_1[2]);
                 from_worker_1=1;
                 MPI_Send(&from_worker_1, 1, MPI_INT, master, 0, MPI_COMM_WORLD);
                 break;
             case worker_2:
                 MPI_Recv(&to_worker_2, 3, MPI_LONG_INT, master, 0, MPI_COMM_WORLD, &status);
                 compute_rows(to_worker_2[0],to_worker_2[1],to_worker_2[2]);
                 from_worker_2=1;
                 MPI_Send(&from_worker_2, 1, MPI_INT, master, 0, MPI_COMM_WORLD);              
                 break;
             case worker_3:
                 MPI_Recv(&to_worker_3, 3, MPI_LONG_INT, master, 0, MPI_COMM_WORLD, &status);
                 compute_rows(to_worker_3[0],to_worker_3[1],to_worker_3[2]);
                 from_worker_3=1;
                 MPI_Send(&from_worker_3, 1, MPI_INT, master, 0, MPI_COMM_WORLD);
                 break;
         }
   }
   MPI_Finalize();
}
