#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "bitmap.h"

#define MAX_SIZE_FILE_NAME 20

int main(int argc, char **argv) {
    int operation = atoi(argv[2]);
    char file_name[MAX_SIZE_FILE_NAME];
    char file_name_processed[MAX_SIZE_FILE_NAME];
    char file_name_copy[MAX_SIZE_FILE_NAME];

    if(argc != 3) {
        printf("The args are incorrect.\n");
        exit(1);
    }

    if(operation > 2) {
        printf("The operation is not valid.\n");
        exit(1);
    }

    strcpy(file_name, argv[1]);
    strcpy(file_name_processed, argv[1]);
    strcpy(file_name_copy, argv[1]);

    FILE* file = fopen(strcat(file_name, ".bmp"), "rb");
    FILE* file_processed = fopen(strcat(file_name_processed, "_processed.bmp"), "wb");
    FILE* file_copy = fopen(strcat(file_name_copy, "_copy.bmp"), "wb");
    
    BITMAPFILEHEADER file_header;
    BITMAPINFOHEADER info_header;
    BITMAPIXEL *pixels;
    BITMAPIXEL *pixels_processed;
    
    if(file == NULL)
        return 0;

    file_header = read_file_header(file);
    info_header = read_info_header(file);
    pixels = read_pixels(file, info_header.width, info_header.height);

    // print_pixels(pixels, info_header.width, info_header.height);
    
    write_file_header(file_copy, file_header);
    write_info_header(file_copy, info_header);
    write_pixels(file_copy, pixels, info_header.width, info_header.height);

    switch(operation) {
        case 1: 
            printf("Swapping channels Blue and Red.\n");
            pixels_processed = swap_b_r(pixels, info_header.width, info_header.height);
        break;
        case 2:
            printf("Transforming colors in black or white.\n");
            pixels_processed = black_and_white(pixels, info_header.width, info_header.height);
        break;
    }
    write_file_header(file_processed, file_header);
    write_info_header(file_processed, info_header);
    write_pixels(file_processed, pixels_processed, info_header.width, info_header.height);

    free(pixels);
    free(pixels_processed);
    fclose(file);
    fclose(file_processed);
    fclose(file_copy);

    return 0;
}