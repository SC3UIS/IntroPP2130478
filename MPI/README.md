# MPI
Este folder contiene los siguientes archivos:
-PascalTriangle.c : este archivo contiene codigo en c para imprimir triangulos de pascal
-mpi_PascalTriangle.c : este archivo contiene la version paralela del archivo anterior
-mpi_PascalTriangle : este archivo es el ejectuble que resulta de la compilacion de mpi_PascalTriangle.c
-PascalTriangle.sbatch : este archivo es un script que permite lanzar el archivo anterior a guane.
-output_PascalTriangle.out : este archivo contiene los resultados de haber lanzado el ejecutable a guane.
-Comparacion.sbatch : permite ejecutar en guane el codigo en mpi, secuencial y openmp para comparar tiempos de ejecucion.
-tiempos.txt : archivo que contiene los diferentes tiempos de ejecucion en el sigueinte orden: secuencial, openmp y mpi.
-Readme.md : el presente archivo. 

## Descripcion general del codigo:
Para paralelizar este programa usando mpi lo que se hizo fue usar 4 procesos: 1 proseco master y 3 para calcular los numeros del triangulos de pascal.
En otras palabras el computo de n filas del triangulo de pascal que se quieran hallar sera repartido entre los tres procesos(a cada proceso le corresponde n/3 filas). 

## Ejecucion:
-No fue posible ejecturarlo en local.

-Guane:luego de compilarlo con mpicc y generado el ejecutable, se uso el script PascalTriangle.sbatch para correrlo en el clauster.Esta
 ejecucion se imprime un triangulo de pascal de n filas.   

 
