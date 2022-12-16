#include "functions.h"

void *pattern_one_thread_output(void *arg) {
  ThreadEntry *thread = (ThreadEntry *)arg;

  printf("Thread %d (%lu) beginning\n", thread->thread_num, thread->thread_id);
  sleep(2);
  printf("Thread %d (%lu) exiting\n", thread->thread_num, thread->thread_id);

  pthread_exit(0);
}

void pattern_one_thread(ThreadEntry *thread, int num_things) {
  for (int ix = 1; ix <= num_things; ++ix) {
    thread[ix].thread_num = ix;

    int thread_creation =
        pthread_create(&thread[ix].thread_id, NULL, pattern_one_thread_output,
                       (void *)&thread[ix]);

    if (thread_creation) {
      printf("Thread creation failed!\n");
    }
  }

  for (int iy = 1; iy <= num_things; ++iy) {
    pthread_join(thread[iy].thread_id, NULL);
  }
}

void *pattern_two_thread_output(void *arg) {
  ThreadEntry *current_thread = (ThreadEntry *)arg;

  /* don't create another thread if... */
  if (current_thread->thread_num == current_thread->max_size) {
    printf("Thread %d (%lu) beginning\n", current_thread->thread_num,
           current_thread->thread_id);
    sleep(2);
    printf("Thread %d (%lu) exiting\n\n", current_thread->thread_num,
           current_thread->thread_id);
    pthread_exit(0);
  }

  printf("Thread %d (%lu) beginning\n", current_thread->thread_num,
         current_thread->thread_id);
  sleep(2);

  ThreadEntry *next_thread = malloc(sizeof(ThreadEntry));
  next_thread->thread_num = current_thread->thread_num + 1;
  next_thread->max_size = current_thread->max_size;

  int next_thread_creation =
      pthread_create(&next_thread->thread_id, NULL, pattern_two_thread_output,
                     (void *)next_thread);

  if (next_thread_creation) {
    printf("Thread creation failed!\n");
  }

  printf("Thread %d (%lu) creating Thread %d (%lu)\n",
         current_thread->thread_num, current_thread->thread_id,
         next_thread->thread_num, next_thread->thread_id);

  printf("Thread %d (%lu) exiting\n\n", current_thread->thread_num,
         current_thread->thread_id);

  pthread_join(next_thread->thread_id, NULL);
  pthread_exit(0);
}

void pattern_two_thread(ThreadEntry *thread, int num_things) {
  thread->thread_num = 1;
  thread->max_size = num_things;

  int thread_creation = pthread_create(
      &thread->thread_id, NULL, pattern_two_thread_output, (void *)thread);

  if (thread_creation) {
    printf("Thread creation failed!\n");
  }

  pthread_join(thread->thread_id, NULL);
}