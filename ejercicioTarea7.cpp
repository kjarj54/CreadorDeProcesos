#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(int argc, char *argv[]) {
  if (argc != 2) {
    fprintf(stderr, "Uso: %s <num_children>\n", argv[0]);
    exit(1);
  }

  int num_children = atoi(argv[1]);
  if (num_children <= 0) {
    fprintf(stderr, "Error: Numero de hijos invalidos\n");
    exit(1);
  }

  printf("Proceso padre: PID=%d, PPID=%d\n", getpid(), getppid());

   // Declarar una variable para contar los hijos creados
  int count = 1;


  while (count <= num_children) {
      pid_t pid = fork();
      if (pid < 0) {
          fprintf(stderr, "Fork failed\n");
          exit(1);
      } else if (pid == 0) {
          printf("Hijos #%d: PID=%d, PPID=%d\n", count, getpid(), getppid());
          exit(0);
      } else {
          wait(NULL);
      }

      // Incrementar la variable en cada iteración
      count++;
  }

  return 0;
}


