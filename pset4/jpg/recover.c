/**
 * recover.c
 *
 * Computer Science 50
 * Problem Set 4
 *
 * Recovers JPEGs from a forensic image.
 */
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdint.h>

int main(int argc, char* argv[]) {
    // Function Declarations
    bool isJpeg(uint8_t buffer[]);
    FILE *make_file(int jpeg_num);
    
    FILE *inptr = fopen("card.raw", "r");
    
    if (inptr == NULL) {
        printf("Could not open card file");
        return 1;
    }
    
    // JPEG file number
    int n = 0;
    
    // 512 byte block
    uint8_t buffer[512];
    
    //sequence through filenames and open files for writing
    while(fread(buffer, sizeof(uint8_t), 512, inptr) != 0)
    {
        while(isJpeg(buffer))
        {
            // create outfile 
            FILE *outfile = make_file(n);
            
            // write out jpeg to outfile
            fwrite(buffer, sizeof(uint8_t), 512, outfile);
            
            // read next block checking for eof 
            if(fread(buffer, sizeof(uint8_t), 512, inptr) == 0)
                break;
            
            // while next block isnt the start of new jpeg keep writing
            while(!isJpeg(buffer))
            {
                fwrite(buffer, sizeof(uint8_t), 512, outfile);
                if(fread(buffer, sizeof(uint8_t), 512, inptr) == 0)
                    break;
            }

            // close outfile 
            fclose(outfile);
            n++;
        }
        
    }
    
    fclose(inptr);
    return 0; 
}

bool isJpeg(uint8_t buffer[]) {
    if ((buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && buffer[3] == 0xe0) || (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && buffer[3] == 0xe1)) {
        return true;
    } else
        return false;
}

FILE *make_file(int jpeg_num) {
    char filename[10];
    sprintf(filename, "%03i.jpg", jpeg_num);
    FILE *outptr = fopen(filename, "w");
    
    if (outptr == NULL) {
        printf("Could not open %s for writing", filename);
        return NULL;
    }
    
    return outptr;
}
