#include <iostream>

#include <SDL.h>
#include <SDL_image.h>

const int window_width = 640;
const int window_height = 480;

struct dimensions {
  public:
    int width;
    int height;
};

dimensions measure_image_dimensions(SDL_Texture *img);
void set_texr_w_and_h(SDL_Rect &texr, dimensions dim);


int main(int argc, char *argv[])
{
	int err = SDL_Init(SDL_INIT_VIDEO);
    if (err > 0) {
        std::cout << "Kappa 1" << std::endl;
    }

    // create an SDL window
	SDL_Window *window = SDL_CreateWindow(
		"Kapparino",
		SDL_WINDOWPOS_UNDEFINED,
		SDL_WINDOWPOS_UNDEFINED,
		window_width,
		window_height,
		0
	);

    // create an SDL renderer
	SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_SOFTWARE);

	SDL_Texture *img = IMG_LoadTexture(renderer, "../Kappa.png");
    
    dimensions dim = measure_image_dimensions(img);

    SDL_Rect texr;
    set_texr_w_and_h(texr, dim);
	
    bool s = true;
	while (true) {
        SDL_RenderClear(renderer);

        s = !s;
        if (s) {
		    SDL_RenderCopy(renderer, img, NULL, &texr);
        }
		
        SDL_Delay(50);
		SDL_RenderPresent(renderer);
	}

	SDL_DestroyWindow(window);
	SDL_Quit();

	return 0;
}

dimensions measure_image_dimensions(SDL_Texture *img) 
{
    int width, height;
    
    SDL_QueryTexture(img, NULL, NULL, &width, &height);
    dimensions d = {width, height};
    return d;
}

void set_texr_w_and_h(SDL_Rect &texr, dimensions dim)
{
    texr.x = window_width/2 - dim.width/2;
    texr.y = window_height/2 - dim.height/2;
    texr.w = dim.width;
    texr.h = dim.height; 
}
