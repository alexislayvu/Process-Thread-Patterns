#include "functions.h"

void print_help_message() {
  printf("\nHow to run the program:\n");
  printf("./main [num_of_things] [process_or_thread] [pattern_num]\n\n");
  printf("num_of_things - The number of subprocesses or threads you want to "
         "create.\n");
  printf("process_or_thread - What type of 'thing' you want to create: a "
         "process or a thread\n");
  printf("pattern_num - Which pattern you want to choose: 1 or 2.\n\n");
  printf("Here are some examples of what you can type in the Console (try it "
         "out yourself!)\n");
  printf("./main 7 process 1\n");
  printf("or\n");
  printf("./main 12 thread 2\n");
}

void print_debug_message() {
  printf("DEBUG MSG #1: num_of_things should be an integer value between 1 and "
         "256.\n");
  printf("DEBUG MSG #2: process_or_thread should be a string input of either "
         "'process' or "
         "'thread'.\n");
  printf("DEBUG MSG #3: pattern_num should be an integer value of either 1 or "
         "2.\n");
}