#ifndef Vuelos_h
#define Vuelos_h

#include "Avion.h"
#include "Fecha.h"

class Vuelos {
    private:
        int pasajeros;
        string numVuelo;
        string llegadaSalida;
        Avion avion;
        Fecha fecha;
    public:
        Vuelos();
        Vuelos(int pasajeros, string numVuelo, string llegadaSalida, Avion avion, Fecha fecha);
        void setPasajeros(int pasajeros);
        void setNumVuelo(string numVuelo);
        void setLlegadaSalida(string llegadaSalida);
        void setAvion(Avion avion);
        void setFecha(Fecha fecha);
        int getPasajeros();
        string getNumVuelo();
        string getLlegadaSalida();
        Avion getAvion();
        Fecha getFecha();
        // bool quedanLugares(int pasajeros, Avion avion);
};

Vuelos::Vuelos(){
    Avion avion();
    Fecha fecha();
    numVuelo = "0";
    pasajeros = 0;
    llegadaSalida = 'a';
}

Vuelos::Vuelos(int pasajeros, string numVuelo, string llegadaSalida, Avion avion, Fecha fecha){
    this-> pasajeros = pasajeros;
    this-> numVuelo = numVuelo;
    this-> llegadaSalida = llegadaSalida;
    this-> avion = avion;
    this-> fecha = fecha;
}

void Vuelos::setPasajeros(int pasajeros){
    this-> pasajeros = pasajeros;
}

void Vuelos::setNumVuelo(string numVuelo){
    this-> numVuelo = numVuelo;
}

void Vuelos::setLlegadaSalida(string llegadaSalida){
    this-> llegadaSalida = llegadaSalida;
}

void Vuelos::setAvion(Avion avion){
    this-> avion = avion;
}

void Vuelos::setFecha(Fecha Fecha){
    this-> fecha = fecha;
}

int Vuelos::getPasajeros(){
    return pasajeros;
}

string Vuelos::getNumVuelo(){
    return numVuelo;
}

string Vuelos::getLlegadaSalida(){
    return llegadaSalida;
}

Avion Vuelos::getAvion(){
    return avion;
}

Fecha Vuelos::getFecha(){
    return fecha;
}

#endif
