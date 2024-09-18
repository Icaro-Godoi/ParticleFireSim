#pragma once

#ifndef ENXAME_H_
#define	ENXAME_H_

#include "Particula.h"

namespace pfs
{
	
class Enxame {
public:
	// Número de particulas a serem criadas
	const static int NPARTICULAS = 2048;

private:
	// Ponteiro para o array de partículas
	Particula * m_pParticulas;
	// Numero em 'ms' em que a última iteração ocorreu
	int lastTime;

public: 
	Enxame();
	virtual ~Enxame();
	void update(int elapsed);
	// Função para extraír o número de partículas
	/* 
	* Função para extraír o número de partículas
	Ponteiro constante apontando para uma partícula constante
	(neste caso, um array de partículas).
	Ponteiro constante para garantir que não aponte para outro lugar,
	partícula constante para garantir que a função não mude a partícula
	*/
	const Particula * const getParticulas() { return m_pParticulas; };
};

}

#endif // !ENXAME_H_
