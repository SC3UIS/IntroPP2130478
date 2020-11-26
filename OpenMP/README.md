## Descripcion general:
Para imprimir un triangulo de pascal con n filas, se rquieren basicamente 3 bucles for: uno que itera sobre n que a su vez esta constituido
por otros dos bucles for(uno para imprimir espacios en blancos y otro para calcular e imprimir los numeros de cada fila). Para
paralelizar el codigo se definieron tres regiones paralelas (una por cada bucle for),que luego de ejecutarse se ordenaron sus resultados
usando la 'clause' ordered.

## Ejecucion:
-Local: Se uso una maquina virtual con 3 procesadores y con Debian.Para compilarlo se uso gcc, y para su ejecucion (usando el comando ./)
 se permitia imprimir un triangulo de pascal con un numero cualquiera de filas.

-Guane:luego de compilarlo con gcc y generado el ejecutable, se uso el script PascalTriangle.sbatch para correrlo en el clauster.Esta
 ejecucion se imprime por defecto un triangulo de pascal de 15 filas.   

 
