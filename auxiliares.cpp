#include "definiciones.h"
#include "auxiliares.h"
#include "gtest/gtest.h"
#include "ejercicios.h"
#include <math.h>

// Auxiliares Generales
// Las funciones de acceso a las columnas todavia no estan definidas asi que todavia no funciona

//ACCESO A LAS COLUMNAS
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

// Auxiliares ejercicio 1
bool vacia ( vector<vector<dato>> s) {
    return s.size()==0;
}

bool esMatriz( vector<vector<dato>> m) {
    for(int i = 0; i<m.size(); i++) {
        for(int j = i+1; j<m.size();  j++) {
            if (m[i].size() != m[j].size()) {
                return false;
            }
        }
    }
    return true;
}

bool individuoEnTabla (individuo ind, eph_i ti) {
    for (int i = 0; i < ti.size(); i++) {
        if (ti[i] == ind)
            return true;
    }
    return false;
}

bool cantidadCorrectaDeColumnasI( eph_i ti) {
    for (int i = 0; i<ti.size(); i++) {
        if (ti[i].size() != cantidadItemsIndividuo)
            return false;
    }
    return true;
}

bool hogarEnTabla ( hogar h, eph_h th ) {
    for (int i = 0; i<th.size(); i++) {
        if (th[i] == h)
            return true;
    }
    return false;
}

bool cantidadCorrectaDeColumnasH (eph_h th) {
    for (int i = 0; i<th.size(); i++) {
        if ( th[i].size() != cantidadItemsHogar)
            return false;
    }
    return true;
}

bool esCasa(hogar h){
    return h[@Tipo]==1;
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

int ingresos(hogar h, eph_i ti){
    int res = 0;
    int tiSize = ti.size();

    for(int i=0;i<tiSize-1;i++){
        if(ti[i][@IndCodusu]==h[@HogCodusu] && ti[i][@IngresoTot]>1){
            res += ti[i][@ingresoTot];
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










