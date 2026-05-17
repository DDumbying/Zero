#include <stdio.h>      // for printf()
#include <unistd.h>     // for read() and close()
#include <fcntl.h>      // for open() and O_RDONLY

int main(int argc, char **argv) {

    unsigned char buffer[16];

    int fd = open(argv[1], O_RDONLY);

    ssize_t bytes_read = read(fd, buffer, 16);

    for (ssize_t i =0; i < bytes_read; i++) {
        printf("%02x ", buffer[i]);
    };

    printf("\n");

    close(fd);

    return 0;
}
