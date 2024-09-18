#define	_USE_MATH_DEFINES
#include "Particula.h"
#include <cmath>
#include <stdlib.h>

namespace pfs
{

Particula::Particula() {
	init();
}

void Particula::init() {
	m_x = 0;
	m_y = 0;

	// Inicia a partícula com uma posição aleatória
	m_direcao = (2 * M_PI * rand()) / RAND_MAX;
	m_velocidade = (0.032 * rand()) / RAND_MAX;

	m_velocidade *= m_velocidade;
}

Particula::~Particula() {

}

void Particula::update(int intervalo) {
	m_direcao += intervalo * 0.00032;

	double xspeed = m_velocidade * cos(m_direcao);
	double yspeed = m_velocidade * sin(m_direcao);

	m_x += xspeed * intervalo;
	m_y += yspeed * intervalo;

	if (m_x < -1 || m_x > 1 || m_y < -1 || m_x > 1) {
		init();
	}
	if (rand()<RAND_MAX/128) {
		init();
	}
}

}