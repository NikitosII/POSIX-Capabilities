// программа 1, в которой выполняется функция, требующая привилегий
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>

int main() {
    const char *filename = "/root/file.txt";
    int fd = open(filename, O_RDONLY);
    if (fd == -1) {
        perror("Error opening file");
        return 1;
    } else {
        printf("File opened successfully\n");
        close(fd);
    }
    return 0;
}
