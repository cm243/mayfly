#include "SDL.h"
#include "graphics.h"

SDL_Surface *load_image( char* filename ) 
{
    //Temporary storage for the image that's loaded
    SDL_Surface* loadedImage = NULL;
    
    //The optimized image that will be used
    SDL_Surface* optimizedImage = NULL;

	//Load the image
    loadedImage = IMG_Load( filename );

	//If nothing went wrong in loading the image
    if( loadedImage != NULL )
    {
        //Create an optimized image
        optimizedImage = SDL_DisplayFormatAlpha( loadedImage );
        
        //Free the old image
        SDL_FreeSurface( loadedImage );
    }

	//Return the optimized image
    return optimizedImage;
}

void apply_surface(int x, int y, SDL_Surface* source, SDL_Surface* destination, SDL_Rect* clip)
{
    //Make a temporary rectangle to hold the offsets
    SDL_Rect offset;
    
    //Give the offsets to the rectangle
    offset.x = x;
    offset.y = y;

	//Blit the surface
    SDL_BlitSurface( source, clip, destination, &offset );
}