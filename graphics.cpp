#include <SDL.h>
#include <SDL_image.h>
#include "graphics.h"

Graphics::Graphics()
{
	SDL_CreateWindowAndRenderer(640, 480, 0, &this->gameWindow, &this->gameRenderer);
	SDL_SetWindowTitle(this->gameWindow, "Cave Story");
}

Graphics::~Graphics()
{
	SDL_DestroyWindow(this->gameWindow);
}

SDL_Surface* Graphics::loadImage(const std::string &filePath)
{
	if (this->spriteSheets.count(filePath) == 0)
	{
		this->spriteSheets[filePath] = IMG_Load(filePath.c_str());
	}
	return spriteSheets[filePath];
}

void Graphics::blitSurface(SDL_Texture* texture, SDL_Rect* sourceRectangle, SDL_Rect* destinationRectangle)
{
	SDL_RenderCopy(this->gameRenderer, texture, sourceRectangle, destinationRectangle);
}

void Graphics::flip()
{
	SDL_RenderPresent(this->gameRenderer);
}

void Graphics::clear()
{
	SDL_RenderClear(this->gameRenderer);
}

SDL_Renderer* Graphics::getRenderer() const
{
	return this->gameRenderer;
}
