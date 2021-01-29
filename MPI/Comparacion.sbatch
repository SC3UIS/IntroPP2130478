#!/bin/bash

#SBATCH --partition=normal
#SBATCH --ntasks=4
#SBATCH --nodes=2
#SBATCH --ntasks-per-node=2

#SBATCH --job-name=Perea
#SBATCH --output=comparacion.txt
#SBATCH --error=tiempos.txt

#SBATCH --mail-type=ALL
#SBATCH --mail-user=bassbeat120@hotmail.com

module load devtools/mpi/openmpi/3.1.4
module load devtools/gcc/6.2.0


time ./s_PascalTriangle 1000
time ./omp_PascalTriangle 1000
time mpirun -np 4 mpi_PascalTriangle 1000

