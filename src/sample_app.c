#include "badgevms/process.h"

#include <stdatomic.h> // for atomic variables
#include <stdbool.h>   // for bool type
#include <stdio.h>
#include <stdlib.h> // for atoi

#include <time.h>
#include <unistd.h> // for usleep
#define ONE_SECOND_IN_USEC 1000 * 1000;

// The current version of this application for printing to the console
int const CURRENT_VERSION = 1;
int         process_start_time = -1;
time_t unix_timestamp;

void version_logger_thread(void *data) {
    while (true) {
        printf("SAMPLE SUBPROCESS: APP V[%d] started at[%ld], ", process_start_time, (long)unix_timestamp);
        usleep(5 * ONE_SECOND_IN_USEC);
    }
}

int main(int argc, char *argv[]) {
    unix_timestamp = time(NULL);
    printf("The current process timestamp is: %ld\n", (long)unix_timestamp);
    thread_create(version_logger_thread, NULL, 4096);

    while (true) {

        usleep(ONE_SECOND_IN_USEC);
        printf("SAMPLE MAIN: APP V[%d] started at[%ld], ", process_start_time, (long)unix_timestamp);
    }
}