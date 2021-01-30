#include <stdio.h>
#include <getopt.h>
#include "pbm.h"

int main( int argc, char *argv[] )
{
    int option;

    for (int i = 0; i < argc; i++){
        printf("Argument[%d]: %s\n", i, argv[i]);
    }

    while((option = getopt(argc, argv, "bg:i:r:smt:n:o:]")) != -1) {
        switch(option) {
            case 'b':
            printf("Option b, converting to PBM.\n");
            break;
            case 'g':
            printf("Option g, converting to a PGM. Arg = %s\n", optarg);
            break;
            case 'i':
            printf("Option i, isolating the RGB channel. Arg = %s\n", optarg);
            break;
            case 'r':
            printf("Option r, removing the specified RGB channel. Arg = %s\n", optarg);
            break;
            case 's':
            printf("Option s, applying sepia transformation.\n");
            break;
            case 'm':
            printf("Option m, vertically mirroring the first half of the image to the second half.\n");
            break;
            case 't':
            printf("Option t, reducing input image to thumbnail based on scaling factor [1-8]. Arg = %s\n", optarg);
            break;
            case 'n':
            printf("Option n, tiling thumbnails of input image based on scaling factor [1-8] Arg = %s\n", optarg);
            break;
            case 'o':
            printf("Option o, writing output image to specified file. Existent output files will be overwritten.");
            break;
            default:
            printf("Unexpected option\n");
            break;
        }
    }



    return 0;
}
