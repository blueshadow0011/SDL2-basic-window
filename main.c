#include <stdio.h>
#include <SDL.h>
int main(int argc,char*args[])
{

	SDL_Window* win;
	SDL_Renderer* render;
	int quit = 0;
	SDL_Event event;
	int result = SDL_Init(SDL_INIT_EVERYTHING);
	win = SDL_CreateWindow("sdl test",
		SDL_WINDOWPOS_CENTERED
		,SDL_WINDOWPOS_CENTERED
		,800
		,600
		,SDL_WINDOW_SHOWN);
	SDL_Rect rect; 
	rect.x = 50;
	rect.y = 50;
	rect.h = 50;
	rect.w = 50;
	
	if (win == NULL) goto cleannquit;
	render = SDL_CreateRenderer(win, -1, SDL_RENDERER_ACCELERATED);
	if (render == NULL){
		fprintf(stderr, "Renderer creation failed: %s\n", SDL_GetError());
		goto cleannquit;
}	
	while (!quit) {
		while (SDL_PollEvent(&event) != 0) {
			switch (event.type)
			{
			case SDL_QUIT:
				quit = 1;
			break;
			}
		}
		//colour of background
		SDL_SetRenderDrawColor(render, 0, 0, 255, 255);

		SDL_RenderClear(render);
		//colour of square
		SDL_SetRenderDrawColor(render, 255, 255, 255, 255);
		SDL_RenderFillRect(render, &rect);
		
		
		
		SDL_RenderPresent(render);
		SDL_Delay(10);
	}
	cleannquit:
	SDL_DestroyWindow(win);



	return 0;
}