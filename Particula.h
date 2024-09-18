#pragma once

#ifndef PARTICULA_H_
#define PARTICULA_H_

namespace pfs
{

class Particula {
	// Velocidade e dire��o das particulas
	double m_velocidade;
	double m_direcao;

public:
	// Coordenadas da part�cula
	double m_x;
	double m_y;

private:
	void init();

public:
	Particula();
	virtual ~Particula();
	void update(int intervalo);
};

}

#endif // !PARTICULA_H_
