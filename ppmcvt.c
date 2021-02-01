#include <stdio.h>
#include <string.h>
#include <errno.h> //Take out later
#include <stdlib.h>
#include <getopt.h>
#include "pbm.h"

int main( int argc, char *argv[] )
{
    //command line processing
    //getopt, strtol

    //read image using ppm_readimage()

    //transformation based on command line option
    //oldimg --> new image
        //can change img in place or:
        //alloc new object
        //assign pixels of new object based on input object and transformation = new image
        //write out new image


    //write new image using write_ppmimage()/

    //Process file names in command line?


    int option;
    char * endPointer;

    for (int i = 0; i < argc; i++){
        printf("Argument[%d]: %s\n", i, argv[i]);
    }

    while((option = getopt(argc, argv, "bg:i:r:smt:n:o:]")) != -1) {
        switch(option) {
            case 'b':
            printf("Option b, converting to PBM.\n");
            break;

            case 'g':
            if(strtol(optarg, &endPointer,10) > 65536){
                errno = 1;
                fprintf(stderr, "Error: Invalid max grayscale pixel value: %s; must be less than 65,536\n", optarg);
                printf(" Value of errno: %d\n ", errno); //Take this out at end. Comments = bad.
                exit(1);
            }
            printf("Option g, converting to a PGM. Arg = %s\n", optarg);
            break;

            case 'i':
            if(strcmp(optarg, "red") != 0 || strcmp(optarg, "green") != 0 || strcmp(optarg, "blue") != 0 ) {
                errno = 1;
                fprintf(stderr, "Error: Invalid channel specification: (%s); should be 'red', 'green' or 'blue'\n", optarg);
                printf(" Value of errno: %d\n ", errno); //Take this out at end. Comments = bad.
                exit(1);
            }
            printf("Option i, isolating the RGB channel. Arg = %s\n", optarg);
            break;

            case 'r':
            if(strcmp(optarg, "red") != 0 || strcmp(optarg, "green") != 0 || strcmp(optarg, "blue") != 0 ) {
                errno = 1;
                fprintf(stderr, "Error: Invalid channel specification: (%s); should be 'red', 'green' or 'blue'\n", optarg);
                printf(" Value of errno: %d\n ", errno); //Take this out at end. Comments = bad.
                exit(1);
            }
            printf("Option r, removing the specified RGB channel. Arg = %s\n", optarg);
            break;

            case 's':
            printf("Option s, applying sepia transformation.\n");
            break;

            case 'm':
            printf("Option m, vertically mirroring the first half of the image to the second half.\n");
            break;

            case 't':
            if(strtol(optarg, &endPointer,10) > 8 || strtol(optarg, &endPointer,10) < 1){
                //Assign the strtol optarg value to a variable for easier use --> then can use strtol in print statement
                errno = 1; //error value of last C value you saw --> usually read, but not write its value
                            //don't ever write erno to a different value -- functions change erno themselves when they fail
                            //value of erno is "ENOERROR" until you call C function
                            //value is the most recent C function you called

                //fprintf(stderr, "Error: Invalid scale factor: %d; must be 1-8\n", atoi(optarg)); //Make into strtol
                fprintf(stderr, "Error: Invalid scale factor: %d; must be 1-8\n", (int) strtol(optarg, NULL, 10)); 
                //use integer type to hold a long -- for this exercise, it doesn't matter -- can also cast
                    //don't cast if the long is too big to be represented by an int
                    
                printf(" Value of errno: %d\n ", errno); //Take this out at end. Comments = bad.
                exit(1);
            }
            printf("Option t, reducing input image to thumbnail based on scaling factor [1-8]. Arg = %s\n", optarg);
            break;

            case 'n':
            if(strtol(optarg, &endPointer,10) > 8 || strtol(optarg, &endPointer,10) < 1){
                errno = 1;
                fprintf(stderr, "Error: Invalid scale factor: %d; must be 1-8\n", atoi(optarg)); //Make into strtol
                printf(" Value of errno: %d\n ", errno); //Take this out at end. Comments = bad.
                exit(1);
            }
            printf("Option n, tiling thumbnails of input image based on scaling factor [1-8] Arg = %s\n", optarg);
            break;

            case 'o':
            printf("Option o, writing output image to specified file. Existent output files will be overwritten.");
            break;

            //Add situation for multiple transformations somewhere

            default:
                //For now
                errno = 1;
                fprintf(stderr, "Usage: ppmcvt [-bgirsmtno] [FILE]\n");
                printf(" Value of errno: %d\n ", errno); //Take this out at end. Comments = bad.
                exit(1);
            //printf("Unexpected option\n"); Take out comments later
            break;
        }
    }



    return 0;
}
