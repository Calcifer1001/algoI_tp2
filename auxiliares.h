#ifndef SOLUCION_AUXILIARES_H
#define SOLUCION_AUXILIARES_H

#include "definiciones.h"


#endif //SOLUCION_AUXILIARES_H

//Acceso a las columnas

int cantidadItemsIndividuo = 11;
int cantidadItemsHogar = 12;
int IndCodusu = INDCODUSU;
int HogCodusu = HOGCODUSU;
int IndAnio = INDANIO;
int IndTrim = INDTRIMESTRE;
int HogAno = HOGANIO;
int HogTrim = HOGTRIMESTRE;
int Componente = COMPONENTE;
int Nivel_Ed = NIVEL_ED;
int Estado = ESTADO;
int Cat_Ocup = CAT_OCUP;
int Edad = CH6;
int Genero = CH4;
int IngresoTot = p47T;
int LugarTrabajo = PP04G;
int Tenencia = II7;
int Region = REGION;
int _500k = MAS_500;
int Tipo = IV1;
int qHabitaciones = IV2;
int qDormitorios = II2;
int trabajaHogar = II3;
int Latitud = HOGLATITUD;
int Longitud = HOGLONGITUD;


//Ejercicios
bool esValida(eph_h th, eph_i ti);
float proporcionDeCasasConHC(eph_h th, eph_i ti, int region);
int cantHogaresEnAnillo(int distDesde, int distHasta, pair < int, int > centro, eph_h th);
int maximaCantidadDeHabitacionesDeUnaCasaEnRegion(eph_h th, int region);
int cantHogaresConNHabitaciones(eph_h th, int region, int habitaciones);