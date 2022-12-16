#include "functions.h"

int main(int argc, char *argv[]) {

  if (strcmp(argv[1], "-h") == 0 || strcmp(argv[1], "-help") == 0) {
    print_help_message();
    exit(1);
  } else if (strcmp(argv[1], "-d") == 0) {
    print_debug_message();
    exit(1);
  }

  if (argc < 4) {
    printf("Not enough arguments supplied. Type './main -h' or './main -help' "
           "for more information.\n");
    exit(1);
  }

  int num_of_things = atoi(argv[1]);
  char *process_or_thread = argv[2];
  int pattern_num = atoi(argv[3]);

  ThreadEntry *thread_to_use;

  if (num_of_things < 1 || num_of_things > 256) {
    printf("Please enter a number between 1 and 256 for argument 1.\n");
    exit(1);
  } else if (pattern_num < 1 || pattern_num > 2) {
    printf("Invalid pattern number! Please enter 1 or 2 for argument 3.\n");
    exit(1);
  }

  if (strcmp(process_or_thread, "process") == 0) {
    if (pattern_num == 1) {
      pattern_one_process(num_of_things);
    } else if (pattern_num == 2) {
      pattern_two_process(num_of_things);
    }
  } else if (strcmp(process_or_thread, "thread") == 0) {
    if (pattern_num == 1) {
      pattern_one_thread(thread_to_use, num_of_things);
    } else if (pattern_num == 2) {
      pattern_two_thread(thread_to_use, num_of_things);
    }
  } else {
    printf("Invalid method! Please enter either 'process' or 'thread' for "
           "argument 2.\n");
    exit(1);
  }

  return 0;
}