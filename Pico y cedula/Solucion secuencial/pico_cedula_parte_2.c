#include <stdio.h>
#include <string.h>
#include <stdlib.h>
void Contar_digitos_cedula(char *filename){
//cuenta las cedulas con 1,2,..,10 digitos a partir de un archivo de texto con numeros
// de cedula
    FILE *fileToread;

    int num_digitos[10]={0,0,0,0,0,0,0,0,0,0};
    int p=0;
    char digito[1]; 

    fileToread = fopen(filename, "r");

//dentro de digito[0] esta el codigo ASCII del caracter leido
//10 es salto de linea


    while (fgets(digito, 2, fileToread) != NULL){
          if(digito[0]!=10){ //control de terminacion de una fila
             p++;
          }else{
             switch(p){
                case 1:
                  num_digitos[0]++;
                  break;
                case 2:
                  num_digitos[1]++;
                  break;
                case 3:
                  num_digitos[2]++;
                  break;
                case 4:
                  num_digitos[3]++;
                  break;
                case 5:
                  num_digitos[4]++;
                  break;
                case 6:
                  num_digitos[5]++;
                  break;
                case 7:
                  num_digitos[6]++;
                  break;
                case 8:
                  num_digitos[7]++;
                  break;
                case 9:
                  num_digitos[8]++;
                  break;
                case 10:
                  num_digitos[9]++;
                  break;
             }
             p=0;
          }

    }
    for(int k=0;k<10;k++)  printf ("cedulas con %d digitos: %d\n",k+1,num_digitos[k]);
    fclose (fileToread);


}

void Listar_cedulas_par_impar(char *filename){
// a partir de un archivo de texto(filename), copia las cedulas par en un archivo de 
// texto y las impar en otro. Tambien imprime el numero de cedulas par e impares 
// encontradas
    FILE *fileToread;
    FILE *par;
    FILE *impar;

    int num_cedulas_par=0,num_cedulas_impar=0;
    char digito[1]; 
    int  p=0,ultimo_digito;
    int* cedula;
    cedula=(int*)malloc(10*sizeof(int));

    fileToread = fopen(filename, "r");
    par = fopen ("Lista_cedulas_par.txt","w");
    impar = fopen ("Lista_cedulas_impar.txt","w");

//dentro de digito[0] esta el codigo ASCII del caracter leido
//10 es salto de linea
// se le caracter por caracter
    
    while (fgets(digito, 2, fileToread) != NULL){
          if(digito[0]!=10){ //control de terminacion de una linea de filename

             ultimo_digito=digito[0]-'0';
             cedula[p]=ultimo_digito;
             p++;
             ultimo_digito=ultimo_digito%2;

          }else{
             if(ultimo_digito==0){
                for(int j=0;j<p;j++) fprintf (par,"%d",cedula[j]);
                fprintf (par,"\n");
                num_cedulas_par++;
             }else{
                for(int k=0;k<p;k++) fprintf (impar,"%d",cedula[k]);
                fprintf (impar,"\n");
                num_cedulas_impar++;
             }
             p=0;
             free(cedula);
             cedula=(int*)malloc(10*sizeof(int));
          }

    }
    printf ("numero de cedulas par: %d\n",num_cedulas_par);
    printf ("numero de cedulas impar: %d\n",num_cedulas_impar);
    fclose (fileToread);
    fclose(par);
    fclose(impar);

}

void main(int argc, char *argv[]){
// este programa lista en un archivo de texto la cedulas pares y las impares en otro
// para luego contar las cedulas con x numeros de digitos. Este programa recibe como
// parametro el archivo de texto con todas los numeros de cedula
    printf ("\n");
    Listar_cedulas_par_impar(argv[1]);
    printf ("se han listado las cedulas correctamente \n");
    printf ("\n");
    printf ("las cuentas sobre las cedulas pares son las siguientes: \n");
    Contar_digitos_cedula("Lista_cedulas_par.txt");
    printf ("\n");
    printf ("las cuentas sobre las cedulas impares son las siguientes: \n");
    Contar_digitos_cedula("Lista_cedulas_impar.txt");
    printf("\n");

}
