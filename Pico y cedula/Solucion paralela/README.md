# OpenMP
Este folder contiene los siguientes archivos:
-PascalTriangle.c : este archivo contiene codigo en c para imprimir triangulos de pascal
-omp_PascalTriangle.c : este archivo contiene la version paralela del archivo anterior
-PascalTriangle : este archivo es el ejectuble que resulta de la compilacion de omp_PascalTriangle.c
-PascalTriangle.sbatch : este archivo es un script que permite lanzar el archivo anterior a guane
-PascalTriangle.txt : este archivo contiene los resultados de haber lanzado el ejecutable a guane
-Readme.md : el presente archivo

## Descripcion general del codigo:
Para imprimir un triangulo de pascal con n filas, se rquieren basicamente 3 bucles for: uno que itera sobre n que a su vez esta constituido
por otros dos bucles for(uno para imprimir espacios en blancos y otro para calcular e imprimir los numeros de cada fila). Para
paralelizar el codigo se definieron tres regiones paralelas (una por cada bucle for),que luego de ejecutarse se ordenaron sus resultados
usando la 'clause' ordered.

## Ejecucion:
-Local: Se uso una maquina virtual con 3 procesadores y con Debian.Para compilarlo se uso gcc, y para su ejecucion (usando el comando ./)
 se permitia imprimir un triangulo de pascal con un numero cualquiera de filas.

-Guane:luego de compilarlo con gcc y generado el ejecutable, se uso el script PascalTriangle.sbatch para correrlo en el clauster.Esta
 ejecucion se imprime por un triangulo de pascal de X filas.   