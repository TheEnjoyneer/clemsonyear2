/*************************
 Christopher Brant
 cbrant
 Lab 3
 Section 2
 Lauren Fuller
 
 File: functions.h
 Purpose: Debugging file for Lab3

 ************************/

#include <stdio.h>
#include <stdlib.h>


typedef struct
{
    char magic[3];
    int height, width, maxval;
}header_t;

typedef struct
{
  unsigned char r, g, b;
}pixel_t;


void readHeader(FILE* ptr, header_t *hdr);

void createHeader(FILE* ptr, header_t *hdr);

void readPixels(FILE* ptr, header_t *hdr, pixel_t** pix);

void writePixels(FILE* ptr, header_t *hdr, pixel_t** pix);
