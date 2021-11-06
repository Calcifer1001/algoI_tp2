#ifndef SOLUCION_AUXILIARES_H
#define SOLUCION_AUXILIARES_H

#include "definiciones.h"


#endif //SOLUCION_AUXILIARES_H

bool esValida(eph_h th, eph_i ti);
float proporcionDeCasasConHC(eph_h th, eph_i ti, int region);
int cantHogaresEnAnillo(int distDesde, int distHasta, pair < int, int > centro, eph_h th);
int maximaCantidadDeHabitacionesDeUnaCasaEnRegion(eph_h th, int region);
int cantHogaresConNHabitaciones(eph_h th, int region, int habitaciones);
void ordenarTablaHogares(eph_h &th);
void ordenarTablaIndividuos(eph_i &ti, eph_h th);