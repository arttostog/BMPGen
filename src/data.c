#include <data.h>

static void random_mode(char* fileBuffer, struct HeaderSizes* sizes) {
    printf("Seed: ");
    unsigned int seed;
    scanf("%d", &seed);
    srand(seed);

    for (int i = HEADER_SIZE; i < sizes->fileSize; ++i)
        fileBuffer[i] = rand() % 256;
}

static void drawing_mode(char* fileBuffer, struct HeaderSizes* sizes) {
    for (int i = 0, red, green, blue, pixelsIndex = HEADER_SIZE; i < sizes->height; ++i)
        for (int j = 0; j < sizes->width; ++j, pixelsIndex += 3) {
            printf("Enter red, green and blue for [%d|%d]: ", j, i);
            scanf("%d %d %d", &red, &green, &blue);
            fileBuffer[pixelsIndex] = (char) red;
            fileBuffer[pixelsIndex + 1] = (char) green;
            fileBuffer[pixelsIndex + 2] = (char) blue;
        }
}

void get_data(char* fileBuffer, struct HeaderSizes* sizes) {
    printf("Select drawing mode (1-2): ");
    int mode;
    scanf("%d", &mode);
    switch (mode)
    {
        default:
        case 1:
            random_mode(fileBuffer, sizes);
            break;
        case 2:
            drawing_mode(fileBuffer, sizes);
            break;
    }
}