#ifndef HEADER_H
#define HEADER_H

#include <stdio.h>

#define HEADER_SIZE 54

struct HeaderSizes {
    int fileSize,
        width,
        height;
};

void create_header(char* headerBuffer, struct HeaderSizes* sizes);

#endif