#include "pbm.h"
#include <stdio.h> //error library



PPMImage * new_ppmimage( unsigned int w, unsigned int h, unsigned int m )
{
    //allocate multi-dimensional arrays
    
    //JUST ALLOCATE MEMORY AND DON'T DO ANYTHING ELSE
    //DON'T PANIC
    //EVERYTHING IS GOING TO BE OK


}

PBMImage * new_pbmimage( unsigned int w, unsigned int h )
{

    //allocate for null characters when it comes to strings

    int *my2DArray = malloc(w * h * sizeof(unsigned int));
                     //allocate w * h * 4 bytes (because of int) of memory

    if (*my2DArray == 0) //See if we have enough memory to grab from heap after program running
    {
        fprintf(stderr, "Error: Cannot allocate memory.\n");
        exit(1);
    }









    //1) define PBMImage pointer
    //2) allocate storage for PBMImage struct for PBMImage pointer
    //3)initialize PBMImage struct height and width

    //do next step 3 times for PPM, only once for this and PGM
    //4)initialize PBMImage struct pixmap (by allocating the required storage*)
        //one 2d array here
        //look at malloc example
        //pixmap should point to an array of pointers, one pointer for each row pixmap
        //each pixmap row pointer should point to an array of unsigned integers, one unsigned integer for each column

    //5)return pointer to PBMImage struct



    //Read PPM file
        //look at pixel values of the PPM and decide whether each pixel should be a 0 or a 1

    //𝐴𝑣𝑒𝑟𝑎𝑔𝑒(𝑅+𝐺+𝐵)<𝑃𝑃𝑀𝑀𝑎𝑥/2 
        //If this is < 2, output 0
        //If this is > 2, output 1
}

PGMImage * new_pgmimage( unsigned int w, unsigned int h, unsigned int m )
{
}

void del_ppmimage( PPMImage * p )
{
    //free the multi-dimensional arrays
}

void del_pgmimage( PGMImage * p )
{
}

void del_pbmimage( PBMImage * p )
{
    free(p);
    //add more stuff here
}

