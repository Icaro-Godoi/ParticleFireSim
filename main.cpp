/*
Autor: �caro Queiroz de Godoi
Programa: Particle Explosion Simulator

Defini��o: Um loop de particulas em movimento ordenado com varia��o de cores e de dura��o infinita
*/

#define SDL_MAIN_HANDLED
#include "Tela.h"
#include "Enxame.h"
#include "Particula.h"

using namespace std;
using namespace pfs;

int main() {
	// Seeding RNG
	srand(time(NULL));

	// Criar a tela a ser modificada
	Tela tela;

	// Inicar tela verificando erro
	if (tela.init() == false) {
		cout << "Erro ao inicializar SDL!" << endl;
		SDL_Quit();
	}

	Enxame enxame;

	const int meiaLargura = Tela::SCREEN_WIDTH / 2;

	Uint8 red = 255;
	Uint8 green = 0;
	Uint8 blue = 0;

	// Loop principal (game loop)
	while (true) {
		// Guardando tempo desde a �ltima itera��o
		int elapsed = SDL_GetTicks();

		// Atualizar part�culas
		enxame.update(elapsed);
		
		// Loop entre cores
		if (red == 255 && green == 0 && blue < 255) // 255,0,0 -> 255,0,255
			blue++;

		if (red > 0 && green == 0 && blue == 255) // 255,0,255 -> 0,0,255
			red--;

		if (red == 0 && green < 255 && blue == 255) // 0,0,255 -> 0,255,255
			green++;

		if (red == 0 && green == 255 && blue > 0) // 0,255,255 -> 0,255,0
			blue--;

		if (red < 255 && green == 255 && blue == 0) // 0,255,0 -> 255,255,0
			red++;

		if (red == 255 && green > 0 && blue == 0) // 255,255,0 -> 255,0,0
			green--;

		/*
		// Alternativa para loop de cores
		unsigned char red = ((1 + sin(elapsed * 0.0001)) * 128);
		unsigned char green = ((1 + sin(elapsed * 0.0002)) * 128);
		unsigned char blue = ((1 + sin(elapsed * 0.0003)) * 128);
		//se for utilizar esse c�digo, incluir <math.h>
		*/

		// Criar part�culas
		const Particula * const pParticulas = enxame.getParticulas(); // Constante representando as part�culas criadas
		for (int i = 0; i < Enxame::NPARTICULAS; i++) {
			Particula particula = pParticulas[i];

			int x = (particula.m_x + 1) * meiaLargura;
			int y = particula.m_y * meiaLargura + Tela::SCREEN_HEIGHT / 2;

			tela.setPixel(x, y, red, green, blue);
		}

		
		// Atualizar cor dos pixels
		/*
		for (int y = 0; y < Tela::SCREEN_HEIGHT; y++) {
			for (int x = 0; x < Tela::SCREEN_WIDTH; x++) {
				tela.setPixel(x, y, red, green, blue);
			}
		}
		*/

		// Cria um blur para as part�culas
		tela.boxBlur();

		// Atualizar a tela
		tela.update();

		// Verificar se h� mensagens ou eventos
		if (tela.processEvents() == false) {
			break;
		}
	}

	tela.close();

	return 0;
};
