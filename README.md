# PixelArtMaker
🎯 Pixel Art Maker made in C and SDL2.

##### Commands :

|Left clic        | Right clic               | c                |
|:-------------:  |:------------------------:|:---------------: |
|color a cell     |erase the color of a cell | erase everything |

|1   |2     |3  |4    |5     |6     |7   |8        |
|:--:|:----:|:-:|:---:|:----:|:----:|:--:|:-------:|
|Blue|Purple|Red|Green|Yellow|Orange|Grey|Dark Blue|

-------

#### Possible improvement: 
* Add a second window to choose the color.
* Add SDL_ttf library.
* Add more color palettes.
* Choose the size of the window 

--------

#### Installation :

You must have the following libraries installed :
* [SDL2](https://www.libsdl.org/download-2.0.php).
* [SDL_image 2.0](https://www.libsdl.org/projects/SDL_image/)(for the icon).

-------

#### Compilation : 

``` 
gcc src/*.c -o bin/PixelArtMaker -I include -L lib -lmingw32 -lSDL2main -lSDL2 -lSDL2_image
```

-------

#### Sreenshots :

<img width="250" src="https://github.com/Louiss-exe/PixelArtMaker/blob/main/screenshots/img1.png">.
<img width="250" src="https://github.com/Louiss-exe/PixelArtMaker/blob/main/screenshots/img2.png">

-----

 ![](https://github.com/Louiss-exe/PixelArtMaker/blob/main/src/icon.png)
