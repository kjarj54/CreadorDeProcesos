#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

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

  printf("Parent process: PID=%d, PPID=%d\n", getpid(), getppid());

  for (int i=1; i<=num_children; i++) {
      pid_t pid = fork();
      if (pid < 0) {
          fprintf(stderr, "Fork failed\n");
          exit(1);
      } else if (pid == 0) {
          printf("Child #%d: PID=%d, PPID=%d\n", i, getpid(), getppid());
          exit(0);
      } else {
          wait(NULL);
      }
  }

  return 0;
}


