#include <stdlib.h>
#include <stdio.h>
#include <header.h>
#include <writer.h>
#include <data.h>

int main(int argc, char* argv[]) {
    if (argc != 2) {
        perror("To few or many args!");
        return 1;
    }

    char headerBuffer[HEADER_SIZE];
    struct HeaderSizes sizes;
    create_header(headerBuffer, &sizes);

    char* fileBuffer = malloc(sizes.fileSize);
    for (int i = 0; i < HEADER_SIZE; ++i)
        fileBuffer[i] = headerBuffer[i];
    
    get_data(fileBuffer, &sizes);
    write_to_file(argv[1], fileBuffer, sizes.fileSize);
    free(fileBuffer);
}