#include "pbm.h"



PPMImage * new_ppmimage( unsigned int w, unsigned int h, unsigned int m )
{
    //allocate multi-dimensional arrays
}

PBMImage * new_pbmimage( unsigned int w, unsigned int h )
{
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
}

