#pragma once
#ifndef TELA_H_
#define TELA_H_

#include <iostream>
#include <SDL.h>

namespace pfs {

class Tela
{
public:
	const static int SCREEN_WIDTH = 1600;
	const static int SCREEN_HEIGHT = 900;
	const static int SCREEN_SIZE = SCREEN_HEIGHT * SCREEN_WIDTH;

private:
	SDL_Window* m_window;
	SDL_Renderer* m_renderer;
	SDL_Texture* m_texture;
	Uint32 * m_buffer1;
	Uint32 * m_buffer2;

public:
	Tela();
	bool init();
	void setPixel(int x, int y, Uint8 red, Uint8 green, Uint8 blue);
	void update();
	void boxBlur();
	bool processEvents();
	void close();
};

}

#endif // !TELA_H_
