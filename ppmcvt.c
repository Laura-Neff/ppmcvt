// THIS CODE IS MY OWN WORK, IT WAS WRITTEN WITHOUT CONSULTING
// A TUTOR OR CODE WRITTEN BY OTHER STUDENTS - LAURA NEFF

#include <stdio.h> //error library
#include <string.h> //for string compare
#include <stdlib.h> //for free, malloc, and NULL
#include <getopt.h> //for getopt
#include "pbm.h"    //pbm library

typedef struct Options {
    char transformation;
    char *transformationValue;
    char *inputFile;
    char *outputFile;
} options;

//Address in memory for structs are not modifiable

//Typdef = means you can make a name of a new variable of this type without saying "struct <class>" every time
//Only meant for your convenience, clarity, and such




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
    //char *endPointer;
    long target;

    options capture;
    capture.transformation = 0;
    capture.transformationValue = NULL;
    capture.outputFile = NULL;

    //for (int i = 0; i < argc; i++){
     //   printf("Argument[%d]: %s\n", i, argv[i]);
    //}

    while((option = getopt(argc, argv, "bg:i:r:smt:n:o:]")) != -1) {
        switch(option) {
            case 'b':
            //capture = (options){.transformation = 'b', .transformationValue = optarg, .inputFile = "foo.pbm", .outputFile = "foo.ppm"};

            if(capture.transformation) //meaning if capture.transformation != 0
            {
                fprintf(stderr, "Error: Multiple transformations specified\n");
                exit(1);
            }

            capture.transformation = 'b';
            //capture.transformationValue = optarg;
            //printf("%s\n", capture.transformationValue);
            printf("%c\n", capture.transformation);

            //printf("Option b, converting to PBM.\n");
            break;

            case 'g':
            target = strtol(optarg, NULL, 10);

            if(capture.transformation) //meaning if capture.transformation != 0
            {
                fprintf(stderr, "Error: Multiple transformations specified\n");
                exit(1);
            }

            capture.transformation = 'g';
            capture.transformationValue = optarg;
            //printf("%s\n", capture.transformationValue);
            //printf("%c\n", capture.transformation);

            if(target > 65536){
                fprintf(stderr, "Error: Invalid max grayscale pixel value: %s; must be less than 65,536\n", optarg);
                exit(1);
            }
            //printf("Option g, converting to a PGM. Arg = %s\n", optarg);
            break;

            case 'i':
            //This is a transformation
            
            if(capture.transformation) //meaning if capture.transformation != 0
            {
                fprintf(stderr, "Error: Multiple transformations specified\n");
                exit(1);
            }

            capture.transformation = 'i';
            //printf("%c\n", capture.transformation);
            //printf("optarg: %s\n",optarg);
            //printf("strcmp optarg: %d\n",strcmp(optarg,"red"));
            if(strcmp(optarg, "red") != 0 && strcmp(optarg, "green") != 0 && strcmp(optarg, "blue") != 0 ) {
                fprintf(stderr, "Error: Invalid channel specification: (%s); should be 'red', 'green' or 'blue'\n", optarg);
                exit(1);
            }
            capture.transformationValue = optarg;
            //printf("Option i, isolating the RGB channel. Arg = %s\n", optarg);
            break;

            case 'r':
            //This is a tranformation
            
            if(capture.transformation) //meaning if capture.transformation != 0
            {
                fprintf(stderr, "Error: Multiple transformations specified\n");
                exit(1);
            }

            capture.transformation = 'r';
            //printf("%c\n", capture.transformation);

            if(strcmp(optarg, "red") != 0 && strcmp(optarg, "green") != 0 && strcmp(optarg, "blue") != 0 ) {
                fprintf(stderr, "Error: Invalid channel specification: (%s); should be 'red', 'green' or 'blue'\n", optarg);
                exit(1);
            }
            capture.transformationValue = optarg;
            //printf("Option r, removing the specified RGB channel. Arg = %s\n", optarg);
            break;

            case 's':
            if(capture.transformation) //meaning if capture.transformation != 0
            {
                fprintf(stderr, "Error: Multiple transformations specified\n");
                exit(1);
            }

            capture.transformation = 's';
            //printf("%c\n", capture.transformation);

            //printf("Option s, applying sepia transformation.\n");
            break;

            case 'm':
            if(capture.transformation) //meaning if capture.transformation != 0
            {
                fprintf(stderr, "Error: Multiple transformations specified\n");
                exit(1);
            }

            capture.transformation = 'm';
            //printf("%c\n", capture.transformation);

            //printf("Option m, vertically mirroring the first half of the image to the second half.\n");
            break;

            case 't':
            if(capture.transformation) //meaning if capture.transformation != 0
            {
                fprintf(stderr, "Error: Multiple transformations specified\n");
                exit(1);
            }

            capture.transformation = 't';
            capture.transformationValue = optarg;
            //printf("%s\n", capture.transformationValue);
            //printf("%c\n", capture.transformation);

            target = strtol(optarg, NULL, 10);
            
            if(target > 8 || target < 1){

                fprintf(stderr, "Error: Invalid scale factor: %d; must be 1-8\n", (int) target); 

                //use integer type to hold a long -- for this exercise, it doesn't matter -- can also cast
                    //don't cast if the long is too big to be represented by an int


                //Assign the strtol optarg value to a variable for easier use --> then can use strtol in print statement
                //errno = 1; //error value of last C value you saw --> usually read, but not write its value
                            //don't ever write erno to a different value -- functions change erno themselves when they fail
                            //value of erno is "ENOERROR" until you call C function
                            //value is the most recent C function you called

                
                    
                //printf(" Value of errno: %d\n ", errno); //Take this out at end. Comments = bad.
                
                exit(1);
            }
            //printf("Option t, reducing input image to thumbnail based on scaling factor [1-8]. Arg = %s\n", optarg);
            break;

            case 'n':
            if(capture.transformation) //meaning if capture.transformation != 0
            {
                fprintf(stderr, "Error: Multiple transformations specified\n");
                exit(1);
            }

            capture.transformation = 'n';
            capture.transformationValue = optarg;
            //printf("%s\n", capture.transformationValue);
            //printf("%c\n", capture.transformation);

            target = strtol(optarg, NULL, 10);
            if(target > 8 || target < 1){
                fprintf(stderr, "Error: Invalid scale factor: %d; must be 1-8\n", (int) target); 
                exit(1);
            }
            //printf("Option n, tiling thumbnails of input image based on scaling factor [1-8] Arg = %s\n", optarg);
            break;

            case 'o':
            capture.outputFile = optarg;
            //outputFile = optarg;
            //printf("Option o, writing output image to specified file. The output file is %s\n", capture.outputFile);
            break;

            //Add situation for multiple transformations somewhere

            default:
                //For now
                fprintf(stderr, "Usage: ppmcvt [-bgirsmtno] [FILE]\n");
                exit(1);
                //printf("Unexpected option\n"); Take out comments later
            break;
        }
    }

     if(argc != optind){
        capture.inputFile = argv[optind];
        //char *inputImage = argv[optind];

    } else {
        fprintf(stderr, "Error: No input file specified\n");
        exit(1);
    }

    if(capture.outputFile == NULL){
        fprintf(stderr, "Error: No output file specified\n");
        exit(1);
    }

    if (capture.transformation == 0){
        capture.transformation = 'b';
    }

    PPMImage *inputPPM = read_ppmfile(capture.inputFile); //Keep this
    //printf("The file was read in successfully.\n");
    //printf("Pixel at (2,2): %d, %d, %d (RGB).\n",
    //            inputPPM->pixmap[0][1][1],
    //            inputPPM->pixmap[1][1][1],
    //            inputPPM->pixmap[2][1][1]);

    PBMImage * outputPBM;
    PGMImage * outputPGM;
    PPMImage * outputPPM;
    double tmp;

    switch(capture.transformation) {
        case 'b':
            //use inputPPM and transform
            outputPBM = new_pbmimage(inputPPM->width, inputPPM->height); //just allocated enough space
            for(int i = 0; i < outputPBM->height; i++){
            //ppm->pixmap[0][h][w] red
            //ppm->pixmap[1][h][w] green
            //ppm->pixmap[2][h][w] blue

                for(int j = 0; j < outputPBM->width; j++) {
                    tmp = (inputPPM->pixmap[0][i][j] + inputPPM->pixmap[1][i][j] + inputPPM->pixmap[2][i][j])/3.;
                    if(tmp > (inputPPM->max)/2) {
                        outputPBM->pixmap[i][j] = 0;
                    } else {
                        outputPBM->pixmap[i][j] = 1;
                    }
                }

                //If this is < 2, output 0
                //If this is > 2, output 1


            }
            write_pbmfile(outputPBM, capture.outputFile);
            del_pbmimage(outputPBM);
            break;
    

    case 'g':
        outputPGM = new_pgmimage(inputPPM->width, inputPPM->height, strtol(capture.transformationValue, NULL, 10));
        for(int i = 0; i < outputPGM->height; i++){
            //ppm->pixmap[0][h][w] red
            //ppm->pixmap[1][h][w] green
            //ppm->pixmap[2][h][w] blue
                for(int j = 0; j < outputPGM->width; j++) {
                    tmp = ((inputPPM->pixmap[0][i][j] + inputPPM->pixmap[1][i][j] + inputPPM->pixmap[2][i][j])/3);
                    tmp = (tmp/inputPPM->max) * outputPGM->max;
                    outputPGM->pixmap[i][j] = (int) tmp;
                }
        }

        write_pgmfile(outputPGM, capture.outputFile);
        del_pgmimage(outputPGM);
        break;

    case 'i':
        outputPPM = new_ppmimage(inputPPM->width, inputPPM->height, inputPPM->max);
        if(strcmp(capture.transformationValue, "red") == 0){
            tmp = 0;
        }
        else if(strcmp(capture.transformationValue, "green") == 0){
            tmp = 1;
        }
        else {
            tmp = 2;
        }
        for(int i = 0; i < outputPPM->height; i++){
            //ppm->pixmap[0][h][w] red
            //ppm->pixmap[1][h][w] green
            //ppm->pixmap[2][h][w] blue
                for(int j = 0; j < outputPPM->width; j++) {
                for(int k = 0; k < 3; k++){
                    if(k != tmp) {
                        outputPPM->pixmap[k][i][j] = 0;
                    }
                    else {
                        outputPPM->pixmap[k][i][j] = inputPPM->pixmap[k][i][j];
                    }
                }
            }
        }

        write_ppmfile(outputPPM, capture.outputFile);
        del_ppmimage(outputPPM);
        break;

    case 'r':
        outputPPM = new_ppmimage(inputPPM->width, inputPPM->height, inputPPM->max);
        if(strcmp(capture.transformationValue, "red") == 0){
            tmp = 0;
        }
        else if(strcmp(capture.transformationValue, "green") == 0){
            tmp = 1;
        }
        else {
            tmp = 2;
        }
        for(int i = 0; i < outputPPM->height; i++){
            //ppm->pixmap[0][h][w] red
            //ppm->pixmap[1][h][w] green
            //ppm->pixmap[2][h][w] blue
                for(int j = 0; j < outputPPM->width; j++) {
                for(int k = 0; k < 3; k++){
                    if(k != tmp) {
                        outputPPM->pixmap[k][i][j] = inputPPM->pixmap[k][i][j];
                    }
                    else {
                        outputPPM->pixmap[k][i][j] = 0;
                    }
                }
            }
        }
        write_ppmfile(outputPPM, capture.outputFile);
        del_ppmimage(outputPPM);
        break;

    case 's':
        outputPPM = new_ppmimage(inputPPM->width, inputPPM->height, inputPPM->max);
        for(int i = 0; i < outputPPM->height; i++){
            //ppm->pixmap[0][h][w] red
            //ppm->pixmap[1][h][w] green
            //ppm->pixmap[2][h][w] blue
                for(int j = 0; j < outputPPM->width; j++) {
                outputPPM->pixmap[0][i][j] = (.393)*inputPPM->pixmap[0][i][j] + (.769)*inputPPM->pixmap[1][i][j] + (.189)*inputPPM->pixmap[2][i][j];
                outputPPM->pixmap[1][i][j] = (.349)*inputPPM->pixmap[0][i][j] + (.686)*inputPPM->pixmap[1][i][j] + (.168)*inputPPM->pixmap[2][i][j];
                outputPPM->pixmap[2][i][j] = (.272)*inputPPM->pixmap[0][i][j] + (.534)*inputPPM->pixmap[1][i][j] + (.131)*inputPPM->pixmap[2][i][j];
                
                
            }
        }

        write_ppmfile(outputPPM, capture.outputFile);
        del_ppmimage(outputPPM);
        break;

    case 'm':
        outputPPM = new_ppmimage(inputPPM->width, inputPPM->height, inputPPM->max);
        tmp = (outputPPM->width)/2;
        for(int i = 0; i < outputPPM->height; i++){
            //ppm->pixmap[0][h][w] red
            //ppm->pixmap[1][h][w] green
            //ppm->pixmap[2][h][w] blue
                for(int j = 0; j < outputPPM->width; j++) {
                    for(int k = 0; k < 3; k++) {
                        if(j>tmp){
                            outputPPM->pixmap[k][i][j] = inputPPM->pixmap[k][i][(int) (2*tmp) - j];
                        }
                        else {
                            outputPPM->pixmap[k][i][j] = inputPPM->pixmap[k][i][j];
                        }
                    }
                
                
                
            }
        }
        write_ppmfile(outputPPM, capture.outputFile);
        del_ppmimage(outputPPM);
        break;

    case 't':
        tmp = strtol(capture.transformationValue, NULL, 10);
        outputPPM = new_ppmimage((int) ((1/tmp)*inputPPM->width), (int) ((1/tmp)*inputPPM->height), inputPPM->max);
        for(int i = 0; i < outputPPM->height; i++){
            //ppm->pixmap[0][h][w] red
            //ppm->pixmap[1][h][w] green
            //ppm->pixmap[2][h][w] blue
                for(int j = 0; j < outputPPM->width; j++) {
                    for(int k = 0; k < 3; k++) {
                        outputPPM->pixmap[k][i][j] = inputPPM->pixmap[k][(int) tmp*i][(int) tmp*j];
                    }
                
                
                
            }
        }
        write_ppmfile(outputPPM, capture.outputFile);
        del_ppmimage(outputPPM);
        break;

    case 'n':
        tmp = strtol(capture.transformationValue, NULL, 10);
        outputPPM = new_ppmimage(inputPPM->width, inputPPM->height, inputPPM->max);
        for(int i = 0; i < outputPPM->height; i++){
            //ppm->pixmap[0][h][w] red
            //ppm->pixmap[1][h][w] green
            //ppm->pixmap[2][h][w] blue
                for(int j = 0; j < outputPPM->width; j++) {
                    for(int k = 0; k < 3; k++) {
                        outputPPM->pixmap[k][i][j] = inputPPM->pixmap[k]\
                            [((int) tmp*i) % inputPPM->height][((int) tmp*j) % inputPPM->width];
                    }
                
                
                
            }
        }
        write_ppmfile(outputPPM, capture.outputFile);
        del_ppmimage(outputPPM);
        break;


    }
    
    del_ppmimage(inputPPM);
    exit(0);

}
    


