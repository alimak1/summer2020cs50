#include <cs50.h>
#include <stdio.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdlib.h>

#define BLOCK_SIZE 512

typedef uint8_t BYTE;

int main(int argc, char *argv[])
{
    // creating space for filename
    char filename[8];
    
    // remebering filenames
    char *inputfile = argv[1];
    
    // creating intput and output files
    FILE *inPtr = fopen(inputfile, "r");
    FILE *outPtr = NULL;
    
    // creating buffer space of 512 bytes
    uint8_t buffer[512];
    
    // image counter, inatally assigned zero
    int imageCounter = 0;
    
    // ussage check
    if (argc != 2)
    {
    printf("USAGE: ./recover image\n");
    return 1;
    }

    if (inputfile == NULL)
    {
    printf("USAGE: ./recover image\n");
    return 1;
    }   

    
    if (inputfile == NULL)
    {
    printf("ERROR: UNABLE TO OPEN FILE %s\n", filename);
    return 1;
    }
    
    // reading memorny card, though even byte of buffer size one-by-one
    while (fread(buffer, sizeof(uint8_t), BLOCK_SIZE, inPtr) || feof(inPtr) == 0)
    {
        // creating boolean for if you at the beginning of a jpeg
        bool jpegHeader = buffer[0] == 0xff
        && buffer[1] == 0xd8
        && buffer[2] == 0xff
        && (buffer[3] & 0xf0) == 0xe0;
        

        if (jpegHeader)
        {
            if (outPtr != NULL) 
            {
                fclose(outPtr);
            }
            // new jpeg found, create a new file '###.jpg'
            // open filename, ready to right
            // jpeg starts as 000 and increases + 1 ... 001, 002, ...
            sprintf(filename, "%03i.jpg", imageCounter);
            outPtr = fopen(filename, "w");
            imageCounter ++;
        }
        
        if (outPtr != NULL)
        {
            fwrite(buffer, 512, 1, outPtr);
        }
    
    }
    // close the files
    fclose(inPtr);
    fclose(outPtr);
    return 0;

}v
