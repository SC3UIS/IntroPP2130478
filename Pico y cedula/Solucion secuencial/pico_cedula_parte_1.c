#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int* Contar_dias_pares(int dia_ini,int num_dias_mes){
// cuenta los dias pares que tiene un mes. La funcion requiere del dia de la semana en 
// que comienza el mes(0-lunes, 1-martes, 2-miercoles,.., 6-domingo) y el numero de 
// dias totales que tiene el mes 
  static int num_dias[]={0,0,0,0,0,0,0};
  int a,b,c;
  for(int i=0;i<num_dias_mes;i++){
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
  int a,b,c;
  for(int i=0;i<num_dias_mes;i++){
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






void main(int argc, char *argv[]){
// este programa requiere 2 argumentos: dia de semana en que inicia el
// mes(lunes-0,martes,..,viernes-6) y el numero de dias en dicho mes 

    int p,t,total_pares,total_impares;
    p=strtol(argv[1], NULL, 10);
    t=strtol(argv[2], NULL, 10);
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
    for(int k=0; k<7; k++){
      printf(" %d ",pares[k]);
      total_pares=total_pares+pares[k];
    }
    printf("\n");
    printf("impar\t");
    for(int l=0; l<7; l++){
      printf(" %d ",impares[l]);
      total_impares=total_impares+impares[l];
    }
    printf("\n");
    printf("\n");
    printf("total dias pares: %d\n",total_pares);
    printf("total dias impares: %d\n",total_impares);
    printf("\n");


}

