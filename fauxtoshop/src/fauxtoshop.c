#include <stdio.h>
#include <stdlib.h>

#define SIZE 54
#define WIDTH 18
#define HEIGHT 22

int main() {
    char headers[SIZE];
    int i, j;

    // Read headers from stdin
    int read = fread(headers, SIZE, 1, stdin);
    if (read != 1)
        exit(1);

    if (headers[0] != 0x42 || headers[1] != 0x4D)
        exit(1);
    
    int bitCount = *(short int*)&headers[28];
    if (bitCount != 24) 
        exit(1);
        
    int offset = *(int*)&headers[10];
    offset -= 54;

    char off[offset];

    if(headers[10] > 0x36){
        for(i=0; i < offset; i++){
            off[i] = getchar();
        }
    }

    int width = *(int*)&headers[WIDTH];
    int height = *(int*)&headers[HEIGHT];

    // Swap width and height in the headers
    *(int*)&headers[WIDTH] = height;
    *(int*)&headers[HEIGHT] = width;

    // Write modified headers to stdout
    fwrite(headers, SIZE, 1, stdout);
    fwrite(off, offset, 1, stdout);

    // Allocate memory for colors
    char ***color = (char ***)malloc(sizeof(char **) * height);
    for (i = 0; i < height; i++)
        color[i] = (char **)malloc(sizeof(char *) * width);

    int padding = (4 - (width * 3) % 4) % 4;
    char pad; // For reading padding

    // Read color data into the array and rotate the image
    for (i = 0; i < height; i++) {
        for (j = 0; j < width; j++) {
            color[i][j] = (char *)malloc(sizeof(char) * 3);
            read = fread(color[i][j], sizeof(char), 3, stdin);
            if(read != 3)
                exit(1);
        }
        // Skip the padding
        for (j = 0; j < padding; j++){
            read = fread(&pad, sizeof(char), 1, stdin);
            if(read != 1)
                exit(1);
        }
    }

    padding = (4 - (height * 3) % 4) % 4;
    // Write rotated color data to stdout
    for (i = width - 1; i >= 0; i--) { 
    for (j = 0; j < height; j++) {
        fwrite(color[j][i], sizeof(char), 3, stdout); 
    }
        // Write padding if necessary
        for (int k = 0; k < padding; k++)
            fputc(0x00, stdout);
    }

    // Free allocated memory
    for (i = 0; i < height; i++) {
        for (j = 0; j < width; j++)
            free(color[i][j]);
        free(color[i]);
    }
    free(color);

    return 0;
}     