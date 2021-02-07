#include "pbm.h"
#include <stdio.h> //error library
#include <stdlib.h>

/*int main( int argc, char *argv[] )
{
    new_pbmimage(10,11);
}
*/

PPMImage * new_ppmimage( unsigned int w, unsigned int h, unsigned int m )
{
    //allocate multi-dimensional arrays

    PPMImage *myNewImage = malloc(sizeof(PPMImage)); //PBM pointer defined and storage allocated. Step 1 and 2 completed
    myNewImage->height = h;  //height initialized.  //-> is the same as the dot operator for a pointer variable   
    myNewImage->width = w;   //width initialized. 
    myNewImage->max = m;  //Step 3 completed
    //printf("%d", myNewImage->height);

    //int *my2DArray = malloc(w * h * sizeof(unsigned int));
                     //allocate w * h * 4 bytes (because of int) of memory

    //myNewImage->pixmap[0] = malloc(w * h * sizeof(unsigned int));  
    //myNewImage->pixmap[1] = malloc(w * h * sizeof(unsigned int)); 
    //myNewImage->pixmap[2] = malloc(w * h * sizeof(unsigned int)); //pixmap allocated. Step 4 complete


    

    //myNewImage->pixmap[0] = malloc(h * sizeof(int *)); //allocate for pixmap rows first

    for(int i = 0; i <= 2; i++){
        myNewImage->pixmap[i] = malloc(h * sizeof(int *));
        for (int j = 0; j < h; j++) {
            myNewImage->pixmap[i][j] = malloc(w * sizeof(unsigned int));
        }
    }

/*
    for(int i = 0; i < h; i++){
        myNewImage->pixmap[i] = malloc(w * sizeof(unsigned int));  //pixmap columns allocated for each row. Step 4 complete

    }

*/


    return(myNewImage); //Pointer returned. Step 5 complete


}

PBMImage * new_pbmimage( unsigned int w, unsigned int h )
{
    //______________________________________________________________________________-//

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
    //______________________________________________________________________________-//


    //*****Side Notes******//
        //Read PPM file
        //look at pixel values of the PPM and decide whether each pixel should be a 0 or a 1

        //𝐴𝑣𝑒𝑟𝑎𝑔𝑒(𝑅+𝐺+𝐵)<𝑃𝑃𝑀𝑀𝑎𝑥/2 
        //If this is < 2, output 0
        //If this is > 2, output 1
    //*****Side Notes******//



    /*
        if (*my2DArray == 0) //See if we have enough memory to grab from heap after program running
        {
            fprintf(stderr, "Error: Cannot allocate memory.\n");
            exit(1);
        } */

     //PBMImage * myNewImage = malloc(sizeof(PBMImage)); //tell program that we are declaring a variable to talk about an address in memory.
                                                        //Then tell program to allocate enough memory from the heap for a PBMImage struct
                                                        //We use pointers when talking about malloc
                                                

    PBMImage *myNewImage = malloc(sizeof(PBMImage)); //PBM pointer defined and storage allocated. Step 1 and 2 completed
    myNewImage->height = h;  //height initialized.  //-> is the same as the dot operator for a pointer variable   
    myNewImage->width = w;   //width initialized. Step 3 completed
    //printf("%d", myNewImage->height);

    //int *my2DArray = malloc(w * h * sizeof(unsigned int));
                     //allocate w * h * 4 bytes (because of int) of memory

    myNewImage->pixmap = malloc(h * sizeof(int *)); //allocate for pixmap rows first
    for(int i = 0; i < h; i++){
        myNewImage->pixmap[i] = malloc(w * sizeof(unsigned int));  //pixmap columns allocated for each row. Step 4 complete

    }

    return(myNewImage); //Pointer returned. Step 5 complete

}

PGMImage * new_pgmimage( unsigned int w, unsigned int h, unsigned int m )
{
    PGMImage *myNewImage = malloc(sizeof(PGMImage)); //PGM pointer defined and storage allocated. Step 1 and 2 completed
    myNewImage->height = h;  //height initialized.  //-> is the same as the dot operator for a pointer variable   
    myNewImage->width = w;   //width initialized. S
    myNewImage->max = m;  //Step 3 completed

    //int *my2DArray = malloc(w * h * sizeof(unsigned int));
                     //allocate w * h * 4 bytes (because of int) of memory

    myNewImage->pixmap = malloc(h * sizeof(int *)); //allocate for pixmap rows first
    for(int i = 0; i < h; i++){
        myNewImage->pixmap[i] = malloc(w * sizeof(unsigned int));  //pixmap columns allocated for each row. Step 4 complete

    }
    
    return(myNewImage); //Pointer returned. Step 5 complete
}

void del_ppmimage( PPMImage * p )
{
    //free the multi-dimensional arrays
    for(int i = 0; i <= 2; i++){
        for(int j = 0; j < p->height; j++){
            free(p->pixmap[i][j]);
        }
        free(p->pixmap[i]);
    }
    free(p);

    //May need to deallocate the max, height, and width


}

void del_pgmimage(PGMImage * p )
{
    //free everything on the left side

    for (int i = 0; i < p->height; i++){
       free(p->pixmap[i]);
    }
    free(p->pixmap);
    free(p);

    //May need to deallocate the max, height, and width



}

void del_pbmimage( PBMImage * p )
{
    for (int i = 0; i < p->height; i++){
       free(p->pixmap[i]);
    }
    free(p->pixmap);
    free(p);

    //may need to deallocate height and width
}

