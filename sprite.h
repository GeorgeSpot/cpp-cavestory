#ifndef SPRITE_H
#define SPRITE_H

#include "graphics.h"
#include <SDL.h>

class Sprite
{
	public:
		Sprite();
		Sprite(Graphics &graphics, const std::string &filePath, int sourceX, int sourceY, int width, int height, float posX, float posY);
		virtual ~Sprite();
		virtual void update();
		void draw(Graphics &graphics, int x, int y);
	private:
		SDL_Rect sourceRectangle;
		SDL_Texture* spriteSheet;
		float x, y;
};

#endif