#include "definiciones.h"
#include "auxiliares.h"
#include "gtest/gtest.h"
#include "ejercicios.h"
#include <math.h>

// Auxiliares Generales
// Las funciones de acceso a las columnas todavia no estan definidas asi que todavia no funciona

bool esCasa(hogar h){
    return h[@Tipo]==1
}

bool esSuHogar(hogar h, individuo i){
    return h[@HogCodusu] == i[@IndCodusu];
}

int cantidadDeHabitantes(hogar h, eph_i ti){
    int res = 0;
    int tiSize = ti.size();

    for(int i=0;i<tiSize;i++){
        if(esSuHogar(h, ti[i])){
            res++;
        }
    }

    return res;
}


// Auxiliares del ejercicio 3
// Las funciones de acceso a las columnas todavia no estan definidas asi que todavia no funciona

bool esHogarValido(hogar h, int region){
    return esCasa(h) && h[@Region]==region && h[@+500k]==0;
}

bool hogarConHacinamientoCritico(hogar h, eph_i ti){
    return cantidadDeHabitantes(h, ti)>3*h[@qDormitorios];
}

int cantHogaresValidos(eph_h th, int region){
    int thSize=th.size();
    int res = 0;

    for(int i=0;i<thSize-1;i++){
        if(esHogarValido(th[i], region)==0){
            res++;
        }
    }
    return res;
}

int cantHogaresValidosConHC(eph_h th, eph_i ti, int region){
    int thSize=th.size();
    int res = 0;

    for(int i=0;i<thSize-1;i++){
        if((esHogarValido(th[i], region)==0) && hogarConHacinamientoCritico(th[i], ti)){
            res++;
        }
    }
    return res;
}

float proporcionDeCasasConHC(eph_h th, eph_i ti, int region){
    float res = 0;

    if(cantHogaresValidos(th, region)>0){
        res=cantHogaresValidosConHC(th, ti, region)/ cantHogaresValidos(th, region);
    }
    return res;
}


// Auxiliares del ejercicio 11
// Las funciones de acceso a las columnas todavia no estan definidas asi que todavia no funciona

float distanciaEuclidiana(pair < int, int > centro, int latitud, int longitud){
    float res = sqrt(pow(centro.first-latitud, 2) + pow(centro.second-longitud, 2));
    return res;
}

bool hogarEnAnillo(int distDesde, int distHasta, pair < int, int > centro, hogar h){
    bool res = false;

    if(distDesde < distanciaEuclidiana(centro, h[@HOGLATITUD], h[@HOGLONGITUD]) && distanciaEuclidiana(centro, h[@HOGLATITUD], h[@HOGLONGITUD]) <= distHasta){
        res = true;
    }

    return res;
}

int cantHogaresEnAnillo(int distDesde, int distHasta, pair < int, int > centro, eph_h th){ // consultar por el eph
    int thSize = th.size();
    int res = 0;

    for(int i=0;i<thSize;i++){
        if(hogarEnAnillo(distDesde, distHasta, centro, th[i])){
            res++;
        }
    }

    return res;
}





