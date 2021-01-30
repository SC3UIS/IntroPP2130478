#!/bin/bash

#SBATCH --partition=normal
#SBATCH --ntasks=4
#SBATCH --nodes=2
#SBATCH --ntasks-per-node=2

#SBATCH --job-name=Perea-MPI
#SBATCH --output=output_PascalTriangle.out
#SBATCH --error=err_PascalTriangle.err

#SBATCH --mail-type=ALL
#SBATCH --mail-user=bassbeat120@hotmail.com


module load devtools/mpi/openmpi/3.1.4
mpirun -np 4 mpi_PascalTriangle 100

