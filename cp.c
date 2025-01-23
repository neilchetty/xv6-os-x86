#include "types.h"
#include "user.h"
#include "fcntl.h"

void cp(char* source, char* dest)
{
    int fdSrc, fdDst;
    if ((fdSrc = open(source, O_RDONLY)) < 0)
    {
        printf(1, "Source file does not exist\n");
        return;
    }
    fdDst = open(dest, O_CREATE | O_WRONLY);
    char buffer;
    while (read(fdSrc, &buffer, 1) > 0)
        write(fdDst, &buffer, 1);
    close(fdDst);
    close(fdSrc);
    return;
}

int main(int argc, char** argv) {
    if(argc < 3) {
        printf(1, "Usage of cp: cp [sourceFile] [destinationFile]\n");
        exit();
    }
    cp(argv[1], argv[2]);
    exit();
}