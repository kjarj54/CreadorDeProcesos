#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <iostream>

using namespace std;

int main(int argc, char *argv[]) {
  if (argc != 2) {
    fprintf(stderr, "Usage: %s <num_children>\n", argv[0]);
    exit(1);
  }

  int num_children = atoi(argv[1]);
  if (num_children <= 0) {
    fprintf(stderr, "Error: Invalid number of children\n");
    exit(1);
  }

  cout<<("Parent process: PID=%d, PPID=%d\n", getpid(), getppid());

   // Declarar una variable para contar los hijos creados
  int count = 1;

  // Usar un bucle while en vez de un for
  while (count <= num_children) {
      pid_t pid = fork();
      if (pid < 0) {
          fprintf(stderr, "Fork failed\n");
          exit(1);
      } else if (pid == 0) {
          cout<<("Child #%d: PID=%d, PPID=%d\n", count, getpid(), getppid());
          exit(0);
      } else {
          wait(NULL);
      }

      // Incrementar la variable en cada iteración
      count++;
  }

  return 0;
}


