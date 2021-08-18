#include "renderer.h"


void BigNgine::RendererBehaviour::Start()
{
	Surface = SDL_LoadBMP( BigNgine::RendererBehaviour::file.c_str() );
	if (!Surface)
	{
		Logger::Error("Couldn't load file: " + file);
		return;
	}
	
	Uint32 colorKey = SDL_MapRGB(Surface->format, 0xFF, 0x00, 0xFF);
	SDL_SetColorKey(Surface, SDL_TRUE, colorKey);
	Position.w = 1;
	Position.h = 1;
	Position.x = 0;
	Position.y = 0;
	Texture = SDL_CreateTextureFromSurface(Game::renderer, Surface);
	if(Texture == nullptr)
	{
		Logger::Error(SDL_GetError());
		return;
	}
}

void BigNgine::RendererBehaviour::Update(int deltaTime)
{
	Position.x = (int)parent->position.x - (int)parent->GetParentScene()->Camera->position.x;
	Position.y = (int)parent->position.y - (int)parent->GetParentScene()->Camera->position.y;
	Position.w = (int)parent->size.x;
	Position.h = (int)parent->size.y;

//	SDL_BlitSurface(Surface, (AnimationRect == nullptr ? nullptr : AnimationRect), Game::windowSurface, &Position);
if(SDL_RenderCopy(Game::renderer, Texture, (AnimationRect == nullptr ? nullptr : AnimationRect), &Position))
	{
		Logger::Error(SDL_GetError());
		return;
	}
}

void BigNgine::RendererBehaviour::Destroy()
{
	SDL_DestroyTexture(Texture);
	SDL_FreeSurface(Surface);
	Surface = nullptr;
}
