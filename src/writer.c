#include <writer.h>

void write_to_file(const char* fileName, const char* buffer, int bufferSize) {
    FILE* file = fopen(fileName, "w");
    for (int i = 0; i < bufferSize; ++i)
        fputc(buffer[i], file);
    fclose(file);
}