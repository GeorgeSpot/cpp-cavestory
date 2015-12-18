#ifndef GRAPHICS_H
#define GRAPHICS_H

#include <string>
#include <map>

struct SDL_Window;
struct SDL_Renderer;

class Graphics
{
	public:
		Graphics();
		~Graphics();
		SDL_Surface* loadImage(const std::string &filePath);
		void blitSurface(SDL_Texture* texture, SDL_Rect* sourceRectangle, SDL_Rect* destinationRectangle);
		void flip();
		void clear();
		SDL_Renderer* getRenderer() const;
	private:
		std::map<std::string, SDL_Surface*> spriteSheets;

		SDL_Window* gameWindow;
		SDL_Renderer* gameRenderer;
};

#endif