#include "bitmap.h"

BITMAPFILEHEADER read_file_header(FILE *file) {
    BITMAPFILEHEADER file_header;
    fseek(file, 0, SEEK_SET);
    fread(&(file_header.type), sizeof(unsigned short), 1, file);
    fread(&(file_header.size), sizeof(unsigned int), 1, file);
    fread(&(file_header.reserved1), sizeof(unsigned short), 1, file);
    fread(&(file_header.reserved2), sizeof(unsigned short), 1, file);
    fread(&(file_header.pixel_data_offset), sizeof(unsigned int), 1, file);   
    return file_header;
}

void write_file_header(FILE *file, BITMAPFILEHEADER file_header) {
    fseek(file, 0, SEEK_SET);
    fwrite(&(file_header.type), sizeof(unsigned short), 1, file);
    fwrite(&(file_header.size), sizeof(unsigned int), 1, file);
    fwrite(&(file_header.reserved1), sizeof(unsigned short), 1, file);
    fwrite(&(file_header.reserved2), sizeof(unsigned short), 1, file);
    fwrite(&(file_header.pixel_data_offset), sizeof(unsigned int), 1, file);   
}

BITMAPINFOHEADER read_info_header(FILE* file) {
    BITMAPINFOHEADER info_header;
    fseek(file, 14, SEEK_SET);
    fread(&(info_header.size), sizeof(unsigned int), 1, file);
    fread(&(info_header.width), sizeof(int), 1, file);
    fread(&(info_header.height), sizeof(int), 1, file);
    fread(&(info_header.planes), sizeof(unsigned short), 1, file);
    fread(&(info_header.bit_count), sizeof(unsigned short), 1, file);
    fread(&(info_header.compression), sizeof(unsigned int), 1, file);
    fread(&(info_header.size_image), sizeof(unsigned int), 1, file);
    fread(&(info_header.x_pels_per_meter), sizeof(int), 1, file);
    fread(&(info_header.y_pels_per_meter), sizeof(int), 1, file);
    fread(&(info_header.total_colors), sizeof(unsigned int), 1, file);
    fread(&(info_header.important_colors), sizeof(unsigned int), 1, file);
    return info_header;
}

void write_info_header(FILE* file, BITMAPINFOHEADER info_header) {
    fseek(file, 14, SEEK_SET);
    fwrite(&(info_header.size), sizeof(unsigned int), 1, file);
    fwrite(&(info_header.width), sizeof(int), 1, file);
    fwrite(&(info_header.height), sizeof(int), 1, file);
    fwrite(&(info_header.planes), sizeof(unsigned short), 1, file);
    fwrite(&(info_header.bit_count), sizeof(unsigned short), 1, file);
    fwrite(&(info_header.compression), sizeof(unsigned int), 1, file);
    fwrite(&(info_header.size_image), sizeof(unsigned int), 1, file);
    fwrite(&(info_header.x_pels_per_meter), sizeof(int), 1, file);
    fwrite(&(info_header.y_pels_per_meter), sizeof(int), 1, file);
    fwrite(&(info_header.total_colors), sizeof(unsigned int), 1, file);
    fwrite(&(info_header.important_colors), sizeof(unsigned int), 1, file);
}

BITMAPIXEL read_pixel(FILE* file) {
    BITMAPIXEL pixel;
    fread(&(pixel.blue), sizeof(unsigned char), 1, file);
    fread(&(pixel.green), sizeof(unsigned char), 1, file);
    fread(&(pixel.red), sizeof(unsigned char), 1, file);
    return pixel;
}

void write_pixel(FILE* file, BITMAPIXEL pixel) {
    fwrite(&(pixel.blue), sizeof(unsigned char), 1, file);
    fwrite(&(pixel.green), sizeof(unsigned char), 1, file);
    fwrite(&(pixel.red), sizeof(unsigned char), 1, file);
}

BITMAPIXEL* read_pixels(FILE* file, int width, int height) {
    BITMAPIXEL *pixels;
    pixels = (BITMAPIXEL *) malloc(width * height * sizeof(BITMAPIXEL));
    for(int i = 0; i < width*height; i++) {
        pixels[i] = read_pixel(file);
    }
    return pixels;
}

void write_pixels(FILE* file, BITMAPIXEL *pixels, int width, int height) {
    for(int i = 0; i < width*height; i++) 
        write_pixel(file, pixels[i]);
    
}

void print_pixels(BITMAPIXEL *pixels, int width, int height) {
    for(int i = 0; i < width*height; i++) 
        printf("[%u,%u,%u] ", pixels[i].blue, pixels[i].green, pixels[i].red);
}

BITMAPIXEL* swap_b_r(BITMAPIXEL *pixels, int width, int height) {
    BITMAPIXEL *pixels_processed = (BITMAPIXEL *) malloc(width * height * sizeof(BITMAPIXEL));
    char *temp = (char *) malloc (sizeof(char) * width * height);
    for(int i = 0; i < width*height; i++) {
        pixels_processed[i].blue = pixels[i].red;
        pixels_processed[i].green = pixels[i].green;
        pixels_processed[i].red = pixels[i].blue;
    }
    free(temp);
    return pixels_processed;
}