#include <stdio.h>

#include <stdlib.h>
#include <unistd.h>

#include <mpi.h>
#include <math.h>

int main() {

  // Initialize the MPI environment
  MPI_Init(NULL, NULL);
  int world_size;
  MPI_Comm_size(MPI_COMM_WORLD, & world_size);

  int rank;
  MPI_Comm_rank(MPI_COMM_WORLD, & rank);

  int SUM = rank;

  // if (rank == 0) {
  //   printf("We are many. %d to be specific.\n", world_size);
  // }


  for (int i = 1; i < world_size; i *= 2) {
    int xor = rank ^ i;
    if (xor < world_size) {
      if (xor < rank) {
        MPI_Send( & SUM, 1, MPI_INT, xor, 0, MPI_COMM_WORLD);
        printf("Done with process %d - sender to %d, iter %d\n", rank, xor, i);
        break;

      } else {
        int number;
        MPI_Recv( & number, 1, MPI_INT, xor, 0, MPI_COMM_WORLD,
          MPI_STATUS_IGNORE);
        printf("Done with process %d - recver from %d, iter %d\n", rank, xor, i);
        SUM += number;
      }

    } else {
      printf("Done with process %d - don't send. would-be partner: %d invalid (>= %d), iter %d\n", rank, xor, world_size, i);
      continue;
    }


  }

  if (rank == 0)
    printf("Final sum is %d\n", SUM);

  MPI_Finalize();

}