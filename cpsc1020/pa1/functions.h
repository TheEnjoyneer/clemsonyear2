/* functions.h
 * Christopher Brant
 * cbrant
 * CPSC 1020 Sec 002 Sp17
 * Yvon Feaster
 * Programming Assignment #1
 * Due 2/26/17 at 11:59 PM
 */

 #ifndef FUNCTIONS_H

typedef struct header_s {
	char magicNum[3];
	int width;
	int height;
	int pixelSpec;
} header_t;

typedef struct pixel_s {
	unsigned char red;
	unsigned char green;
	unsigned char blue;
} pixel_t;

void readHeader(header_t *head, FILE *inFile);
void readImage(header_t *head, pixel_t **image, FILE *inFile);
void chooseTransform(header_t *head, pixel_t **image, FILE *outFile);
void printP6Image(header_t *head, pixel_t **image, FILE *outFile);
void grayScaleImage(header_t *head, pixel_t **image, FILE *outFile);
void flipImage(header_t *head, pixel_t **image, FILE *outFile);
void rotateLeft(header_t *head, pixel_t **image, FILE *outFile);
void rotateRight(header_t *head, pixel_t **image, FILE *outFile);
void color2Negative(header_t *head, pixel_t **image, FILE *outFile);
void reprint(header_t *head, pixel_t **image, FILE *outFile);
void horizontalMirror(header_t *head, pixel_t **image, FILE *outFile);
void verticalMirror(header_t *head, pixel_t **image, FILE *outFile);

#endif