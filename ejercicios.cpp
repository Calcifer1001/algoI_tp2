#include "ejercicios.h"
#include "auxiliares.h"
#include "definiciones.h"

using namespace std;
// Implementacion Problema 1
bool esEncuestaValida ( eph_h th, eph_i ti ) {

    if (esValida(th, ti))
        return true;
    else
        return false;

}

// Implementacion Problema 2
vector < int > histHabitacional ( eph_h th, eph_i ti, int region ) {
	vector < int > resultado = {-1, -1, -1, -1, -1, -1};
	
	// TODO
    resultado.clear();

    for(int i=1;i<=maximaCantidadDeHabitacionesDeUnaCasaEnRegion(th, region);i++){
        resultado.push_back(cantHogaresConNHabitaciones(th, region, i));
    }

	return resultado;
}

// Implementacion Problema 3
vector< pair < int, float > > laCasaEstaQuedandoChica ( eph_h th, eph_i ti ) {

    vector<pair<int,float>> resp = {make_pair(1,-1.0),
                                        make_pair(40, -1.0),
                                        make_pair(41, -1.0),
                                        make_pair(42,-1.0),
                                        make_pair(43,-1.0),
                                        make_pair(44,-1.0)};
	// TODO

    int respSize = resp.size();

    for(int i=0;i<respSize;i++){
        resp[i].second = proporcionDeCasasConHC(th,ti, resp[i].first);
    }

    return resp;
}

// Implementacion Problema 4
bool creceElTeleworkingEnCiudadesGrandes ( eph_h t1h, eph_i t1i, eph_h t2h, eph_i t2i ) {
	bool resp = false;
	
	// TODO
	
  return  resp;
}

// Implementacion Problema 5
int costoSubsidioMejora( eph_h th, eph_i ti, int monto ){
	int resp = -1;
	
	// TODO
	
  return  resp;
}

// Implementacion Problema 6
join_hi generarJoin( eph_h th, eph_i ti ){

    join_hi resp;

    for (int i= 0; i<ti.size(); i++) {
        for (int h =0; h<th.size(); h++) {
            if (ti[i][IndCodusu]=th[h][HogCodusu]) {
           /* if (ti[i][ItemInd::INDCODUSU]=th[h][ItemHogar::HOGCODUSU]) {    lu fijate que la forma correcta de acceder a las columnas es asi, no hace falta definir otras funciones*/
                resp.push_back(make_pair(th[h],ti[i]));
            }
        }
    }

    return  resp;

}

// Implementacion Problema 7
void ordenarRegionYCODUSU (eph_h & th, eph_i & ti) {
	
	// TODO
	
	return;
}

// Implementacion Problema 8
vector < hogar > muestraHomogenea( eph_h & th, eph_i & ti ){
    hogar h = {};
    vector < hogar > resp = {h};

    // TODO

    return  resp;
}

// Implementacion Problema 9
void corregirRegion( eph_h & th, eph_i ti ) {
	
	// TODO
	
	return;
}

// Implementacion Problema 10
vector < int > histogramaDeAnillosConcentricos( eph_h th, eph_i ti, pair < int, int > centro, vector < int > distancias ){
	vector < int > resp = {};
	
	// TODO
    int distanciasSize = distancias.size();

    resp.push_back(cantHogaresEnAnillo(0,distancias[0],centro, th));

    for(int i=0;i<distanciasSize-1;i++){  // Consultar sobre la especificacion si i=0 o i=1
        resp.push_back(cantHogaresEnAnillo(distancias[i],distancias[i+1],centro, th));
    }
	
	return resp;
}

// Implementacion Problema 11
pair < eph_h, eph_i > quitarIndividuos(eph_i & ti, eph_h & th, vector < pair < int, dato > >  busqueda ){
    eph_h rth = {{-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1}};
    eph_i rti = {{-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1}};
    pair < eph_h, eph_i > resp = make_pair(rth, rti);
		
	// TODO

	
	return resp;
}
