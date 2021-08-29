/*
constants.h
-----------
Role: define the constants of the program.
*/

#ifndef DEF_CONSTANTS
#define DEF_CONSTANTS

    #define BLOCK_SIZE       30 //case/square size (100*100)

    //SQUARE ONLY (NB_BLOCKS_WIDTH = NB_BLOCKS_HEIGHT)
    #define NB_BLOCKS_WIDTH  20 //Number of blocks in the window -width-
    #define NB_BLOCKS_HEIGHT 20 //Number of blocks in the window -height-

    #define COUNT           (NB_BLOCKS_WIDTH*NB_BLOCKS_HEIGHT) //Number of blocks in the windows -all-
    #define WH_SIZE         (BLOCK_SIZE*NB_BLOCKS_WIDTH) //size in pixel of the side of the window

    #define WINDOW_WIDTH    (BLOCK_SIZE*NB_BLOCKS_WIDTH) //adapt the window according to the number of blocks
    #define WINDOW_HEIGHT   (BLOCK_SIZE*NB_BLOCKS_HEIGHT)


    struct color{int r;int g;int b;};

    #define BLUE         (struct color){27,79,114}
    #define PURPLE       (struct color){81,46,95}
    #define RED          (struct color){120,40,31}
    #define GREEN        (struct color){11,83,69}
    #define YELLOW       (struct color){125,102,8}
    #define ORANGE       (struct color){126,81,9}
    #define GREY         (struct color){123,125,125}

    #define LINES        (struct color){23,32,42}//Dark blue
    #define BACKGROUND   (struct color){245, 245, 245}


    enum clic{LEFT,RIGHT};


#endif