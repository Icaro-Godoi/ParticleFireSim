#include "Tela.h"

namespace pfs {

Tela::Tela(): m_window(NULL), m_renderer(NULL), m_texture(NULL), m_buffer1(NULL), m_buffer2(NULL){

}

bool Tela::init() {
	// Verificar inicialização do SDL
	if (SDL_Init(SDL_INIT_VIDEO) < 0) {
		return false;
	}

	// Criar janela
	m_window = SDL_CreateWindow("Particle Fire Explosion",
		SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH,
		SCREEN_HEIGHT, 0);

	// Verificar criação da janela
	if (m_window == NULL) {
		SDL_Quit();
		return false;
	}

	// Criar renderizador e textura
	m_renderer = SDL_CreateRenderer(m_window, -1, SDL_RENDERER_PRESENTVSYNC);
	m_texture = SDL_CreateTexture(m_renderer, SDL_PIXELFORMAT_RGBA8888,
		SDL_TEXTUREACCESS_STATIC, SCREEN_WIDTH, SCREEN_HEIGHT);

	// Verificar criação do renderizador
	if (m_renderer == NULL) {
		SDL_DestroyWindow(m_window);
		SDL_Quit();
		return false;
	}

	// Verificar criação da textura
	if (m_texture == NULL) {
		SDL_DestroyRenderer(m_renderer);
		SDL_DestroyWindow(m_window);
		SDL_Quit();
		return false;
	}

	// Alocar memória para os pixels
	m_buffer1 = new Uint32[SCREEN_SIZE];
	m_buffer2 = new Uint32[SCREEN_SIZE];

	// Setar pixels para preto
	memset(m_buffer1, 0, SCREEN_SIZE * sizeof(Uint32));
	memset(m_buffer2, 0, SCREEN_SIZE * sizeof(Uint32));

	return true;
}

void Tela::setPixel(int x, int y, Uint8 red, Uint8 green, Uint8 blue) {

	if (x < 0 || x >= SCREEN_WIDTH || y < 0 || y >= SCREEN_HEIGHT) {
		return;
	}

	Uint32 color = 0;

	color += red;
	color <<= 8;
	color += green;
	color <<= 8;
	color += blue;
	color <<= 8;
	color += 0xFF;

	m_buffer1[(y * SCREEN_WIDTH) + x] = color;
}

// Atualizar a textura
void Tela::update() {
	SDL_UpdateTexture(m_texture, NULL, m_buffer1, SCREEN_WIDTH * sizeof(Uint32));
	SDL_RenderClear(m_renderer);
	SDL_RenderCopy(m_renderer, m_texture, NULL, NULL);
	SDL_RenderPresent(m_renderer);
}

// Troca os buffers para que os pixels estejam no buffer2 e as partículas sejam desenhadas com base no buffer1
void Tela::boxBlur() {
	Uint32 * temp = m_buffer1;

	m_buffer1 = m_buffer2;
	m_buffer2 = temp;

	for (int y = 0; y < SCREEN_HEIGHT; y++) {
		for (int x = 0; x < SCREEN_WIDTH; x++) {

			/* 
			* 0 0 0
			* 0 1 0
			* 0 0 0
			*/

			int redTotal = 0;
			int greenTotal = 0;
			int blueTotal = 0;

			for (int row = -1; row <= 1; row++) {
				for (int col = -1; col <= 1; col++) {
					int currentX = x + col;
					int currentY = y + row;

					if (currentX >= 0 && currentX < SCREEN_WIDTH && currentY >= 0 && currentY < SCREEN_HEIGHT) {
						Uint32 color = m_buffer2[currentY * SCREEN_WIDTH + currentX];

						Uint8 red = color >> 24;
						Uint8 green = color >> 16;
						Uint8 blue = color >> 8;

						redTotal += red;
						greenTotal += green;
						blueTotal += blue;
					}

				}

			}
			Uint8 red = redTotal / 9;
			Uint8 green = greenTotal / 9;
			Uint8 blue = blueTotal / 9;

			setPixel(x, y, red, green, blue);
		}
	}
}

// Processa e lida com inputs do usuário
bool Tela::processEvents() {
	SDL_Event evento;

	while (SDL_PollEvent(&evento)) {
		if (evento.type == SDL_QUIT) {
			return false;
		}
	}
	return true;
}

// Termina o programa
void Tela::close() {
	delete[] m_buffer1;
	delete[] m_buffer2;
	SDL_DestroyTexture(m_texture);
	SDL_DestroyRenderer(m_renderer);
	SDL_DestroyWindow(m_window);
	SDL_Quit();
}

}