//to show the mount of RAM used.
#include <stdio.h>
#include <sys/resource.h>

int main() {
    struct rusage usage;
    getrusage(RUSAGE_SELF, &usage);
    printf("Memory usage: %ld kilobytes\n", usage.ru_maxrss);
    return 0;
}

//output: 17744 kilobytes