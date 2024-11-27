#include <stdlib.h>
#include <stdio.h>

#define HEADER_SIZE 54
char header[HEADER_SIZE] = {
    0x42, 0x4D,
    0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00,
    0x36, 0x00, 0x00, 0x00,
    0x28, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00,
    0x01, 0x00, 0x18, 0x00,
    0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00,
    0xC4, 0x0E, 0x00, 0x00,
    0xC4, 0x0E, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00
};

int main(int argc, char* argv[]) {
    if (argc != 2) {
        perror("To few or many args!");
        return 1;
    }

    printf("Width and height: ");
    int width, height;
    scanf("%d %d", &width, &height);

    int imageSize = width * height * 3,
        fileSize = imageSize + HEADER_SIZE;

    for (int i = 0; i < 4; ++i) {
        header[i + 2] = ((char*) &fileSize)[i];
        header[i + 18] = ((char*) &width)[i];
        header[i + 22] = ((char*) &height)[i];
        header[i + 34] = ((char*) &imageSize)[i];
    }

    char* pixels = malloc(imageSize);
    int mode;
    printf("Select drawing mode (1-2): ");
    scanf("%d", &mode);
    switch (mode)
    {
        default:
        case 1:
            printf("Use seed (0-1): ");
            unsigned seed;
            scanf("%d", &seed);
            if (seed) {
                printf("Select seed: ");
                scanf("%d", &seed);
                srand(seed);
            }

            for (int i = 0; i < imageSize; ++i)
                pixels[i] = rand() % 256;
            break;
        case 2:
            for (int i = 0, pixelsIndex = 0; i < height; ++i)
                for (int j = 0, red, green, blue; j < width; ++j, pixelsIndex += 3) {
                    printf("Enter red, green and blue for [%d|%d]: ", j, i);
                    scanf("%d %d %d", &red, &green, &blue);
                    pixels[pixelsIndex] = (char) red;
                    pixels[pixelsIndex + 1] = (char) green;
                    pixels[pixelsIndex + 2] = (char) blue;
                }
            break;
    }

    FILE* file = fopen(argv[1], "w");
    for (int i = 0; i < HEADER_SIZE; ++i)
        fputc(header[i], file);
    for (int i = 0; i < imageSize; ++i)
        fputc(pixels[i], file);
    fclose(file);
    free(pixels);
}