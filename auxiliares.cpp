#include "definiciones.h"
#include "auxiliares.h"
#include "gtest/gtest.h"
#include "ejercicios.h"
#include <math.h>

// Auxiliares Generales

bool esCasa(hogar h){
    return h[ItemHogar::IV1]==1;
}

bool esSuHogar(hogar h, individuo i){
    return h[ItemHogar::HOGCODUSU] == i[ItemInd::INDCODUSU];
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

int ingresos(hogar h, eph_i ti){
    int res = 0;
    int tiSize = ti.size();

    for(int i=0;i<tiSize-1;i++){
        if(ti[i][ItemInd::INDCODUSU]==h[ItemHogar::HOGCODUSU] && ti[i][ItemInd::p47T]>1){
            res += ti[i][ItemInd::p47T];
        }
    }

    return res;
}

bool hogarEnTabla(hogar h, eph_h th){
    bool res = false;
    int thSize = th.size();

    for(int i=0;i<thSize;i++){
        if(th[i]==h){
            res = true;
        }
    }

    return res;
}


// Auxiliares del ejercicio 3

bool esHogarValido(hogar h, int region){
    return (esCasa(h) && h[ItemHogar::REGION]==region && h[ItemHogar::MAS_500]==0);
}

bool hogarConHacinamientoCritico(hogar h, eph_i ti){
    return (cantidadDeHabitantes(h, ti)>3*h[ItemHogar::II2]);
}

int cantHogaresValidos(eph_h th, int region){
    int thSize=th.size();
    int res = 0;

    for(int i=0;i<thSize;i++){
        if(esHogarValido(th[i], region)){
            res++;
        }
    }
    return res;
}

int cantHogaresValidosConHC(eph_h th, eph_i ti, int region){
    int thSize=th.size();
    int res = 0;

    for(int i=0;i<thSize;i++){
        if(esHogarValido(th[i], region) && hogarConHacinamientoCritico(th[i], ti)){
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

float distanciaEuclidiana(pair < int, int > centro, int latitud, int longitud){
    float res = sqrt(pow(centro.first-latitud, 2) + pow(centro.second-longitud, 2));
    return res;
}

bool hogarEnAnillo(int distDesde, int distHasta, pair < int, int > centro, hogar h){
    bool res = false;

    if(distDesde < distanciaEuclidiana(centro, h[ItemHogar::HOGLATITUD], h[ItemHogar::HOGLONGITUD]) && distanciaEuclidiana(centro, h[ItemHogar::HOGLATITUD], h[ItemHogar::HOGLONGITUD]) <= distHasta){
        res = true;
    }

    return res;
}

int cantHogaresEnAnillo(int distDesde, int distHasta, pair < int, int > centro, eph_h th){ // consultar por la especificacion si entra el eph como parametro
    int thSize = th.size();
    int res = 0;

    for(int i=0;i<thSize;i++){
        if(hogarEnAnillo(distDesde, distHasta, centro, th[i])){
            res++;
        }
    }

    return res;
}








