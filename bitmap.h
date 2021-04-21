#ifndef BITMAP_H
    #define BITMAP_H

#include <stdio.h>
#include <stdlib.h>

/*!< https://medium.com/sysf/bits-to-bitmaps-a-simple-walkthrough-of-bmp-image-format-765dc6857393 */

/*!< Type that represents a BMP file */
#define BF_TYPE 0x4D42 /* "MB" */

/**** BMP file header structure ****/
typedef struct  {
    unsigned short type; /* Magic number for file, bfType deve ser = "MB" */
    unsigned int size; /* Size of file */
    unsigned short reserved1; /* Reserved */
    unsigned short reserved2; /* ... */
    unsigned int   pixel_data_offset; /* Offset to bitmap data */
} BITMAPFILEHEADER; 

/**** BMP file info structure ****/
typedef struct {
    unsigned int size; /* Size of info header */
    int width; /* Width of image */
    int height; /* Height of image */
    unsigned short planes; /* Number of color planes */
    unsigned short bit_count; /* Number of bits per pixel */
    unsigned int compression; /* Type of compression to use */
    unsigned int size_image; /* Size of image data */
    int x_pels_per_meter; /* X pixels per meter */
    int y_pels_per_meter; /* Y pixels per meter */
    unsigned int total_colors; /* Number of colors used */
    unsigned int important_colors; /* Number of important colors */
} BITMAPINFOHEADER; 

/** Because the file we are reading are bit_count = 24, there are 24bits per pixels and it is equals to 3 bytes per pixel
By definition, each scale of color (B, G, R) will have 1 byte to define a number (between 0 and 255) 
So, each pixel will have 3 bytes, one to each scale of color (B, G, R) and each color has 2^8=256 different values that can set */
typedef struct {
    /*!< https://www.ime.usp.br/~pf/algoritmos/aulas/int.html */
    unsigned char blue;
    unsigned char green;
    unsigned char red;
} BITMAPIXEL;

BITMAPFILEHEADER read_file_header(FILE *file);
void write_file_header(FILE *file, BITMAPFILEHEADER file_header);
BITMAPINFOHEADER read_info_header(FILE* file);
void write_info_header(FILE* file, BITMAPINFOHEADER info_header);
BITMAPIXEL read_pixel(FILE* file);
void write_pixel(FILE* file, BITMAPIXEL pixel);
BITMAPIXEL* read_pixels(FILE* file, int width, int height);
void write_pixels(FILE* file, BITMAPIXEL *pixels, int width, int height);
void print_pixels(BITMAPIXEL *pixels, int width, int height);
BITMAPIXEL* swap_b_r(BITMAPIXEL *pixels, int width, int height);

#endif