#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <time.h>
#include <unistd.h>

typedef struct ThreadEntry {
  pthread_t thread_id;
  int thread_num;
  int max_size;
  int current_thread_counter;
  int threads_remaining;
} ThreadEntry;

void pattern_one_process(int num_things);
void pattern_two_process(int num_things);

void *pattern_one_thread_output(void *arg);
void pattern_one_thread(ThreadEntry *thread, int num_things);

void *pattern_two_thread_output(void *arg);
void pattern_two_thread(ThreadEntry *thread, int num_things);

void print_help_message();
void print_debug_message();

#endif