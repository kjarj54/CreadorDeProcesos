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

  int num_hijos = atoi(argv[1]);
  if (num_hijos <= 0) {
    fprintf(stderr, "Error: Numero de hijos invalidos\n");
    exit(1);
  }

  printf("Proceso padre: PID=%d, PPID=%d\n", getpid(), getppid());

   // Declarar una variable para contar los hijos creados
  int cont = 1;


  while (cont <= num_hijos) {
      pid_t pid = fork();
      if (pid < 0) {
          fprintf(stderr, "Fork failed\n");
          exit(1);
      } else if (pid == 0) {
          printf("Hijos #%d: PID=%d, PPID=%d\n", cont, getpid(), getppid());
          exit(0);
      } else {
          wait(NULL);
      }

      // Incrementar la variable en cada iteración
      cont++;
  }

  return 0;
}


