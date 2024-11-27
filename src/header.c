#include <header.h>

static char header[HEADER_SIZE] = {
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

void create_header(char* headerBuffer, struct HeaderSizes* sizes) {
    printf("Width and height: ");
    scanf("%d %d", &sizes->width, &sizes->height);

    int imageSize = sizes->width * sizes->height * 3;
    sizes->fileSize = imageSize + HEADER_SIZE;

    for (int i = 0; i < HEADER_SIZE; ++i)
        headerBuffer[i] = header[i];

    for (int i = 0; i < 4; ++i) {
        headerBuffer[i + 2] = ((char*) &sizes->fileSize)[i];
        headerBuffer[i + 18] = ((char*) &sizes->width)[i];
        headerBuffer[i + 22] = ((char*) &sizes->height)[i];
        headerBuffer[i + 34] = ((char*) &imageSize)[i];
    }
}