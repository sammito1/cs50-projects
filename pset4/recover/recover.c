// This program recovers individual JPEG images contained within a .raw file.
#include <stdio.h>
#include <stdint.h>

// defining a type BYTE from unsigned integer (8 bits in size)
typedef uint8_t BYTE;


int main(int argc, char *argv[])
{
    // ensure proper usage (1 command line argument)
    if (argc != 2)
    {
        fprintf(stderr, "Usage: ./recover card.raw\n");
        return 1;
    }

    // open infile, if inptr = NULL, return 2 to main()
    FILE *inptr = fopen(argv[1], "r");
    if (inptr == NULL)
    {
        fprintf(stderr, "File could not be opened.\n");
        return 2;
    }

    // create buffer
    BYTE buffer[512];

    // initialize filename string and img pointer-to-file
    char filename[] = "000.jpg";

    // declare img pointer-to-file to a new file with filename "000.jpg"
    FILE *img = fopen(filename, "w");

    // create counter for file naming
    int filecounter = 0;

    // repeat until end of card
    while (fread(&buffer, 512, 1, inptr) != 0)
    {
        // is buffer is beginning of a new JPEG? ...
        if (buffer[0] == 0xff && buffer[1] == 0xd8 &&
            buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0)
        {
            // close previous JPEG file
            fclose(img);

            // open new outfile (with name depending on filecounter)
            sprintf(filename, "%03i.jpg", filecounter);
            img = fopen(filename, "w");

            // increase count of filecounter
            filecounter++;
        }
        // write buffer into respective file
        fwrite(&buffer, 512, 1, img);
    }

    // close infile inptr
    fclose(inptr);
}