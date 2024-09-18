#include "Enxame.h"

namespace pfs
{

Enxame::Enxame(): lastTime(0) {
	// Alocar mem�ria para as part�culas
	m_pParticulas = new Particula[NPARTICULAS];
}
Enxame::~Enxame() {
	// Desalocar mem�ria das part�culas
	delete[] m_pParticulas;
}

void Enxame::update(int elapsed) {
	int interval = elapsed - lastTime;

	for (int i = 0; i < NPARTICULAS; i++) {
		m_pParticulas[i].update(interval);
	}
	
	lastTime = elapsed;
}

}