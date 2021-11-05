#include "definiciones.h"
#include "auxiliares.h"
#include "gtest/gtest.h"
#include "ejercicios.h"
#include <math.h>

// Auxiliares Generales
//Ejercicio 1
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

bool hayHogarConCodigo (eph_h th, int c) {
    for (int h = 0; h < th.size(); h++) {
        if ( th[h][HogCodusu] == c )
            return true;
    }
    return false;
}

bool hayIndividuosSinHogares (eph_i ti, eph_h th) {
    for (int i = 0; i<ti.size(); i++) {
        if (not hayHogarConCodigo(th, ti[i][IndCodusu]))
            return true;
    }
    return false;
}

bool hayIndividuoConCodigo (eph_i ti, int c) {
    for (int i = 0; i<ti.size(); i++) {
        if (ti[i][IndCodusu] == c)
            return true;
    }
    return false;
}

bool hayHogaresSinIndividuos (eph_i ti, eph_h th) {
    for (int h = 0; h < th.size(); h++ ) {
        if (not hayIndividuoConCodigo(ti, th[h][HogCodusu]))
            return true;
    }
    return false;
}

bool mismoCodusuYComponente (individuo i1, individuo i2) {
    return (i1[IndCodusu] == i2[IndCodusu]) && (i1[Componente] == i2[Componente]);
}

bool hayRepetidosI (eph_i ti) {
    for (int n1 = 0; n1 < ti.size(); n1++) {
        for (int n2 = 0; n2<ti.size() && n2 != n1; n2++ ) {
            if (mismoCodusuYComponente(ti[n1], ti[n2]))
                return true;
        }
    }
    return false;
}

bool hayRepetidosH (eph_h th) {
    for (int n1 = 0; n1 < th.size(); n1++) {
        for (int n2 = 0; n2<th.size() && n2 != n1; n2++ ) {
            if (th[n1][HogCodusu] == th[n2][HogCodusu])
                return true;
        }
    }
    return false;
}

int anio(eph_h th) {
    return th[0][1];
}

int trimestre (eph_h th) {
    return th[0][2];
}

bool mismoAnioYTrimestre (eph_i ti, eph_h th) {
    for (int i = 0; i<ti.size(); i++) {
        if ((ti[i][IndAnio] != anio(th)) || (ti[i][IndTrim] != trimestre(th)))
            return false;
    }
    for (int h = 0; h < th.size(); h++) {
        if ((th[h][HogAno] != anio(th)) || (th[h][HogTrim] != trimestre(th)))
            return false;
    }
    return true;
}

bool esSuHogar(hogar h, individuo i){
    return h[HogCodusu] == i[IndCodusu];
}

int cantHabitantes (hogar h, eph_i ti) {
    int suma = 0;
    for (int k= 0; k < ti.size(); k++) {
        if (esSuHogar(h, ti[k]))
            suma++;
    }
    return suma;
}

bool menosDe21MiembrosPorHogar (eph_h th, eph_i ti) {
    for (int i = 0; i<th.size(); i++) {
        if (cantHabitantes(th[i], ti) >= 21)
            return false;
    }
    return true;
}

bool esCasa(hogar h){
    return h[Tipo]==1;
}

bool cantidadValidaDormitorios (eph_h th) {
    for (int h = 0; h<th.size(); h++) {
        if (th[h][qHabitaciones] < th[h][qDormitorios])
            return false;
    }
    return true;
}

bool individuoValido (individuo i) {
    if (i[IndCodusu]>0 && i[Componente]>0 && i[IndTrim]>0 && i[IndTrim]<=4 && i[Genero]>0 &&
        i[Genero]<=4 &&i[Edad]>=0 && i[Edad]>=0 && (i[Nivel_Ed]==0 || i[Nivel_Ed]==1) &&
        i[Estado]>=-1 && i[Estado]<=1 && i[Cat_Ocup]>=0 && i[Cat_Ocup]<=4 && (i[IngresoTot]>=0 ||
                                                                              i[IngresoTot]==-1) && i[LugarTrabajo]>=0 && i[LugarTrabajo]<=10 )
        return true;
    else
        return false;
}

bool valoresEnRangoI(eph_i ti) {
    for (int i = 0; i<ti.size(); i++) {
        if (not individuoValido(ti[i]))
            return false;
    }
    return true;
}

bool valorRegionValido(int r) {
    return (r==1) || (40<=r && r<=44);
}

bool hogarValido(hogar h) {
    if (h[HogCodusu]>0 && h[HogTrim]>0 && h[HogTrim]<=4 && h[Tenencia]>0 && h[Tenencia]<=3 &&
        valorRegionValido(h[Region]) && (h[_500k]==0 || h[_500k]==1) && h[Tipo]>0 && h[Tipo]<=5 &&
        h[qHabitaciones]>0 && h[qDormitorios]>=1 && (h[trabajaHogar]==1 || h[trabajaHogar]==2))
        return true;
    else
        return false;
}

bool valoresEnRangoH (eph_h th) {
    for (int h = 0; h<th.size(); h++) {
        if (not hogarValido(th[h]))
            return false;
    }
    return true;
}

bool esValida(eph_h th, eph_i ti) {
    if (not vacia(ti) && not vacia(th) && esMatriz(ti) && esMatriz(th) && cantidadCorrectaDeColumnasI(ti) &&
        cantidadCorrectaDeColumnasH(th) && not hayIndividuosSinHogares(ti, th) && not hayHogaresSinIndividuos(ti, th) &&
        not hayRepetidosI(ti) && not hayRepetidosH(th) && mismoAnioYTrimestre(ti, th) && menosDe21MiembrosPorHogar(th, ti) &&
        cantidadValidaDormitorios(th) && valoresEnRangoI(ti) && valoresEnRangoH(th))
        return true;
    else
        return false;
}



//Ejercicios 3 y 11
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








