#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h> 
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



int* sumador(int* vector,int p){
    switch(p){
        case 1:
            vector[0]++;
            break;
        case 2:
            vector[1]++;
            break;
        case 3:
            vector[2]++;
            break;
        case 4:
            vector[3]++;
            break;
        case 5:
            vector[4]++;
            break;
        case 6:
            vector[5]++;
            break;
        case 7:
            vector[6]++;
            break;
        case 8:
            vector[7]++;
            break;
        case 9:
            vector[8]++;
            break;
        case 10:
            vector[9]++;
            break;
    }
    return vector;
    
}

void main(int argc, char *argv[]){
    
    int id_proceso,from_worker_1=1,from_worker_2=1,mes_1[2],mes_2[2],mes_3[2];
    
    MPI_Init(&argc, &argv);

    MPI_File fileToread; 
    MPI_Status status; 
    MPI_Comm_rank(MPI_COMM_WORLD, &id_proceso); 
    
    MPI_File_open(MPI_COMM_WORLD,argv[1], MPI_MODE_RDONLY, MPI_INFO_NULL, &fileToread);
     
    if(id_proceso==master){
        mes_1[0]=0;
        mes_1[1]=28;
    
        mes_2[0]=0;
        mes_2[1]=31;
    
        mes_3[0]=3;
        mes_3[1]=30;
        printf("Informacion sobre el mes de febrero, marzo y abril de 2021 respectivamente :\n");
        imprimir_mes(mes_1[0],mes_1[1]); //imprime el primer mes         
   
        MPI_Send(&mes_2, 2, MPI_INT, worker_1, 0, MPI_COMM_WORLD);
        MPI_Recv(&from_worker_1, 1, MPI_INT, worker_1, 0, MPI_COMM_WORLD, &status);        

        MPI_Send(&mes_3, 2, MPI_INT, worker_2, 0, MPI_COMM_WORLD);
        MPI_Recv(&from_worker_2, 1, MPI_INT, worker_2, 0, MPI_COMM_WORLD, &status);
        
        int num_cedulas_par=0,num_cedulas_impar=0;
        char digito[1]; 
        int  p=0,ultimo_digito,j,k,*aux,
        num_digitos_par[10]={0,0,0,0,0,0,0,0,0,0},num_digitos_impar[10]={0,0,0,0,0,0,0,0,0,0};
        bool eof=true;
        
        while(eof){
          MPI_File_read_all(fileToread,digito,1,MPI_CHAR,&status);
          if(digito[0]==102) break;
//-----------------jugar con digito[0]---------------------------------------------------------------- 
          if(digito[0]!=10){ //control de terminacion de una linea de filename

             ultimo_digito=digito[0]-'0';
             p++;
             ultimo_digito=ultimo_digito%2;

          }else{
             if(ultimo_digito==0){
                aux=sumador(num_digitos_par,p);
                for(j=0;j<10;j++) num_digitos_par[j]=aux[j];
                num_cedulas_par++;
             }else{
                aux=sumador(num_digitos_impar,p);
                for(k=0;k<10;k++) num_digitos_impar[k]=aux[k];
                num_cedulas_impar++;
             }
             p=0;
          }

//-----------------jugar con digito[0]----------------------------------------------------------------        
        }  
        printf ("las cuentas sobre las cedulas pares son las siguientes: \n");
        for(j=0;j<10;j++) printf ("cedulas con %d digitos: %d\n",j+1,num_digitos_par[j]); 
        printf("\n");
        printf ("las cuentas sobre las cedulas impares son las siguientes: \n");
        for(k=0;k<10;k++) printf ("cedulas con %d digitos: %d\n",k+1,num_digitos_par[k]); 
        printf("\n");
        printf ("numero de cedulas pares: %d\n",num_cedulas_par);
        printf ("numero de cedulas impares: %d\n",num_cedulas_impar);
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