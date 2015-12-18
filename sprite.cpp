#include "sprite.h"
#include "graphics.h"

Sprite::Sprite(Graphics &graphics, const std::string &filePath, int sourceX, int sourceY, int width, int height, float posX, float posY) : x(posX), y(posY)
{
	this->sourceRectangle.x = sourceX;
	this->sourceRectangle.y = sourceY;
	this->sourceRectangle.w = width;
	this->sourceRectangle.h = height;

	this->spriteSheet = SDL_CreateTextureFromSurface(graphics.getRenderer(), graphics.loadImage(filePath));
}

Sprite::~Sprite()
{

}

void Sprite