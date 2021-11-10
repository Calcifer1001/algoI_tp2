#ifndef SOLUCION_AUXILIARES_H
#define SOLUCION_AUXILIARES_H

#include "definiciones.h"

bool esValida(eph_h th, eph_i ti);
float proporcionDeCasasConHC(eph_h th, eph_i ti, int region);
int cantHogaresEnAnillo(int distDesde, int distHasta, pair < int, int > centro, eph_h th);
int maximaCantidadDeHabitacionesDeUnaCasaEnRegion(eph_h th, int region);
int cantHogaresConNHabitaciones(eph_h th, int region, int habitaciones);
void ordenarTablaHogares(eph_h &th);
void ordenarTablaIndividuos(eph_i &ti, eph_h th);
int ingresos(hogar h, eph_i ti);
int diferenciaDeIngresos(eph_i ti, hogar hog1, hogar hog2);
void buscarSiguienteHogar(eph_h th, eph_i ti, int dif, vector<hogar>& temp, int nEsimoHogar, vector<int> hogaresAnteriores, int maximoActual);
float proporcionTeleworking(eph_h th, eph_i ti);

// Ejercicio 5
bool tieneCasaPropia(hogar h);
bool tieneCasaChica(hogar h, eph_i ti);

// Ejercicio 9
void cambiaRegionesGBAaPampeana(eph_h &th);

// Ejercicio 10
bool cumpleCondicion(vector<pair<int, dato>> busqueda, individuo ind);


#endif //SOLUCION_AUXILIARES_H


