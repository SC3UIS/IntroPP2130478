#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <mpi.h>
#define master 0
#define worker_1 1
#define worker_2 2

int* Contar_dias_pares(int dia_ini,int num_dias_mes){
// cuenta los dias pares que tiene un mes. La funcion requiere del dia de la semana en 
// que comienza el mes(0-lunes, 1-martes, 2-miercoles,.., 6-domingo) y el numero de 
// dias totales que tiene el mes 
  static int num_dias[]={0,0,0,0,0,0,0};
  int a,b,c,i;
  for(i=0;i<num_dias_mes;i++){
     a=dia_ini+i;
     b=a%7;
     c=i+1;
     c=c%2;
     switch(b){
      case 0:
         if(c==0)
            num_dias[0]++;
         break;
      case 1:
         if(c==0)
            num_dias[1]++;
         break;

      case 2:
         if(c==0)
            num_dias[2]++;
         break;

      case 3:
         if(c==0)
            num_dias[3]++;
         break;

      case 4:
         if(c==0)
            num_dias[4]++;
         break;

      case 5:
         if(c==0)
            num_dias[5]++;
         break;

      case 6:
         if(c==0)
            num_dias[6]++;
         break;
     }
  }
  return num_dias;
}

int* Contar_dias_impares(int dia_ini,int num_dias_mes){
// cuenta los dias impares que tiene un mes. La funcion requiere del dia de la semana 
// en que comienza el mes(0-lunes, 1-martes, 2-miercoles,.., 6-domingo) y el numero de 
// dias totales que tiene el mes 
  static int num_dias[]={0,0,0,0,0,0,0};
  int a,b,c,i;
  for(i=0;i<num_dias_mes;i++){
     a=dia_ini+i;
     b=a%7;
     c=i+1;
     c=c%2;
     switch(b){
      case 0:
         if(c!=0)
            num_dias[0]++;
         break;

      case 1:
         if(c!=0)
            num_dias[1]++;
         break;

      case 2:
         if(c!=0)
            num_dias[2]++;
         break;

      case 3:
         if(c!=0)
            num_dias[3]++;
         break;

      case 4:
         if(c!=0)
            num_dias[4]++;
         break;

      case 5:
         if(c!=0)
            num_dias[5]++;
         break;

      case 6:
         if(c!=0)
            num_dias[6]++;
         break;
     }
  }
  return num_dias;
}






void imprimir_mes(int p,int t){
// esta funcion requiere 2 argumentos: dia de semana en que inicia el
// mes(lunes-0,martes,..,viernes-6) y el numero de dias en dicho mes. 

    int total_pares=0,total_impares=0,k,l;
    int* pares=Contar_dias_pares(p,t);
    int* impares=Contar_dias_impares(p,t);

    printf("\n");
    printf("\t");
    printf("lu ");
    printf("ma ");
    printf("mi ");
    printf("ju ");
    printf("vi ");
    printf("sa ");
    printf("do\n");
    printf("par\t");
    for(k=0; k<7; k++){
      printf(" %d ",pares[k]);
      total_pares=total_pares+pares[k];
    }
    printf("\n");
    printf("impar\t");
    for(l=0; l<7; l++){
      printf(" %d ",impares[l]);
      total_impares=total_impares+impares[l];
    }
    printf("\n");
    printf("\n");
    printf("total dias pares: %d\n",total_pares);
    printf("total dias impares: %d\n",total_impares);
    printf("\n");


}


void main(int argc, char *argv[]){
    // esta funcion requiere 6 argumentos: dia de semana en que inicia el
   // mes(lunes-0,martes,..,viernes-6) y el numero de dias en dicho mes. Esto para cada uno de los tres meses de interes 
    int id_proceso,from_worker_1=1,from_worker_2=1,from_worker_3=1;
    int mes_1[2],mes_2[2],mes_3[2];
    
    mes_1[0]=strtol(argv[1], NULL, 10);
    mes_1[1]=strtol(argv[2], NULL, 10);
    
    mes_2[0]=strtol(argv[3], NULL, 10);
    mes_2[1]=strtol(argv[4], NULL, 10);
    
    mes_3[0]=strtol(argv[5], NULL, 10);
    mes_3[1]=strtol(argv[6], NULL, 10);
  
    MPI_Status status;
    
    MPI_Init(&argc, &argv);
    MPI_Comm_rank(MPI_COMM_WORLD, &id_proceso); 
    if(id_proceso==master){
         imprimir_mes(mes_1[0],mes_1[1]); //imprime el primer mes 
        
   
         MPI_Send(&mes_2, 2, MPI_INT, worker_1, 0, MPI_COMM_WORLD);
         MPI_Recv(&from_worker_1, 1, MPI_INT, worker_1, 0, MPI_COMM_WORLD, &status);
        

         MPI_Send(&mes_3, 2, MPI_INT, worker_2, 0, MPI_COMM_WORLD);
         MPI_Recv(&from_worker_2, 1, MPI_INT, worker_2, 0, MPI_COMM_WORLD, &status);
        
    }else{
        switch(id_proceso){
            case worker_1:
                 MPI_Recv(&mes_2, 2, MPI_INT, master, 0, MPI_COMM_WORLD, &status);
                 imprimir_mes(mes_2[0],mes_2[1]); //imprime el segundo mes 
                 MPI_Send(&from_worker_1, 1, MPI_INT, master, 0, MPI_COMM_WORLD);
                 break;
                
            case worker_2:
                 MPI_Recv(&mes_3, 2, MPI_INT, master, 0, MPI_COMM_WORLD, &status);
                 imprimir_mes(mes_3[0],mes_3[1]); //imprime el tercer mes 
                 MPI_Send(&from_worker_2, 1, MPI_INT, master, 0, MPI_COMM_WORLD);              
                 break;
        }
    }
    MPI_Finalize();


        
}