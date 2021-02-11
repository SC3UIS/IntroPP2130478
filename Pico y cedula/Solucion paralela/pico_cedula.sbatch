#!/bin/bash

#SBATCH --partition=normal  # Nombre de la particion - Los nombres se obtienen con el comando sinfo
#SBATCH --job-name=OpenMP   # Nombre de la tarea a ejecutar - puede ser cualquiera
#SBATCH --nodes=1           # Cantidad de nodos a usar
#SBATCH --ntasks=1          # Numero de tareas a ejecutar
#SBATCH --cpus-per-task=16  # Numero de cores asignados a cada tarea
#SBATCH --ntasks-per-node=1 # Numero total de tareas a ejecutar por nodo
#SBATCH --output=output_pico_cedula.txt # Archivo de salida donde se encuentran los resultados de la ejecucion
#SBATCH --error=error_pico_cedula.err  # Archivo que contiene los errores de ejecucion

module load devtools/gcc/6.2.0    # Modulo que contiene el software a usar
module load devtools/mpi/openmpi/3.1.4

if [ -n "$SLURM_CPUS_PER_TASK" ]; then
  omp_threads=$SLURM_CPUS_PER_TASK
  else
    omp_threads=1
    fi
    
    export OMP_NUM_THREADS=$omp_threads

time mpirun -np 3 mpi_pico_cedula leer.txt

