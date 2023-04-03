//To show the Disc usage for the root file system.
#include <stdio.h>
#include <sys/statvfs.h>

int main() {
    struct statvfs vfs;
    statvfs("/", &vfs);
    printf("Total disk space: %lu bytes\n", vfs.f_blocks * vfs.f_frsize);
    printf("Free disk space: %lu bytes\n", vfs.f_bfree * vfs.f_frsize);
    printf("Used disk space: %lu bytes\n", (vfs.f_blocks - vfs.f_bfree) * vfs.f_frsize);
    printf("Disk usage: %f%%\n", 100.0 - (double)vfs.f_bfree / (double)vfs.f_blocks * 100.0);
    return 0;
}

/* Output:
Total disk space: 241925345280 bytes
Free disk space: 204391985152 bytes
Used disk space: 37533360128 bytes
Disk usage: 15.514439% */
