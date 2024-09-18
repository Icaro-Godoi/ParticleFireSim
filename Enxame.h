#pragma once

#ifndef ENXAME_H_
#define	ENXAME_H_

#include "Particula.h"

namespace pfs
{
	
class Enxame {
public:
	// N�mero de particulas a serem criadas
	const static int NPARTICULAS = 2048;

private:
	// Ponteiro para o array de part�culas
	Particula * m_pParticulas;
	// Numero em 'ms' em que a �ltima itera��o ocorreu
	int lastTime;

public: 
	Enxame();
	virtual ~Enxame();
	void update(int elapsed);
	// Fun��o para extra�r o n�mero de part�culas
	/* 
	* Fun��o para extra�r o n�mero de part�culas
	Ponteiro constante apontando para uma part�cula constante
	(neste caso, um array de part�culas).
	Ponteiro constante para garantir que n�o aponte para outro lugar,
	part�cula constante para garantir que a fun��o n�o mude a part�cula
	*/
	const Particula * const getParticulas() { return m_pParticulas; };
};

}

#endif // !ENXAME_H_
