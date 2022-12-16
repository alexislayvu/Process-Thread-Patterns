#include "functions.h"

void pattern_one_process(int num_things) {
  for (int ix = 1; ix <= num_things; ++ix) {
    pid_t child_process = fork();

    if (child_process < 0) {
      printf("child_process fork failed!\n");
    }
    
    if (child_process == 0) {
      printf("Process %d (%d) beginning\n", ix, getpid());
      sleep(2);
      printf("Process %d (%d) exiting\n", ix, getpid());
      exit(0);
    }
  }

  for (int iy = 1; iy <= num_things; ++iy) {
    wait(NULL);
  }
}

void pattern_two_process(int num_things) {
  pid_t child_process = fork();

  for (int ix = 1; ix <= num_things; ++ix) {
    if (child_process < 0) {
      printf("child_process fork failed!\n");
    }
    
    if (child_process == 0) {
      printf("Process %d (%d) beginning\n", ix, getpid());
      sleep(2);

      pid_t grandchild_process = fork();
      
      if (grandchild_process < 0) {
        printf("granchild_process fork failed!\n");
      }
      
      if (grandchild_process == 0) {
        if (ix == num_things) { /* don't create another process */
          printf("Process %d (%d) exiting\n", ix, getppid());
          exit(0);
        }

        printf("Process %d (%d) creating Process %d (%d)\n", ix, getppid(),
               ix + 1, getpid());
        printf("Process %d (%d) exiting\n\n", ix, getppid());
        sleep(2);
      } else {
        wait(NULL);
        exit(0);
      }
    } else {
      wait(NULL);
      exit(0);
    }
  }
}