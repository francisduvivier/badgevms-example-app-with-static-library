// #include "badgevms/process.h"
//
// #include <stdbool.h>   // for bool type
// #include <stdio.h>
// #include <stdlib.h> // for atoi
//
// #include <time.h>
#include <unistd.h> // for usleep

#define ONE_SECOND_IN_USEC (1000 * 1000)
//
// // The current version of this application for printing to the console
// const int CURRENT_VERSION = 1;
// time_t process_start_time;

// void version_logger_thread(void *data) {
//     while (true) {
//         printf("SAMPLE SUBPROCESS: APP V[%d] started at[%ld]\n", CURRENT_VERSION, (long)process_start_time);
//         usleep(5 * ONE_SECOND_IN_USEC);
//     }
// }

#include "stdio.h"

int main(int argc, char *argv[]) {
    // process_start_time = time(NULL);
    // printf("The current process timestamp is: %ld\n", (long)process_start_time);
    //
    // thread_create(version_logger_thread, NULL, 4096);

    while (1) {
        usleep(ONE_SECOND_IN_USEC);
        printf("SAMPLE MAIN: APP V[%d] started at[%ld]\n", 0, (long)0);
    }
    return 0;
}
