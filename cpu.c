//To show the percentage of CPU used.
#include <stdio.h>
#include <sys/resource.h>
#include <sys/time.h>

double get_cpu_usage() {
    struct rusage usage;
    getrusage(RUSAGE_SELF, &usage);

    double total_time = usage.ru_utime.tv_sec + usage.ru_stime.tv_sec +
                        (usage.ru_utime.tv_usec + usage.ru_stime.tv_usec) / 1000000.0;

    struct timeval current_time;
    gettimeofday(&current_time, NULL);

    double elapsed_time = current_time.tv_sec + current_time.tv_usec / 1000000.0;

    return total_time / elapsed_time * 100.0;
}

int main() {
    double cpu_usage = get_cpu_usage();
    printf("CPU usage: %f%%\n", cpu_usage);
    return 0;
}

//output:0.000000%