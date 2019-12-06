#include<iostream>
#include<string>
#include<fstream> 
#include<vector>
#include<algorithm>

using namespace std;

#include"Avion.h"
#include"Vuelos.h"
#include"Fecha.h"

int reng = 0;

Fecha FechaHora(string fecha_str, string hora_str) {
  int ano,mes,dia,hora,minuto;
  ano = stoi(fecha_str.substr(0,4));
  mes = stoi(fecha_str.substr(5,7));
  dia = stoi(fecha_str.substr(8,10));
  hora = stoi(hora_str.substr(0,2));
  minuto = stoi(hora_str.substr(3,5));
  Fecha f(ano,mes,dia,hora,minuto);
  return f;
}

int CuentaFechas(Vuelos vuelos[]){
  Fecha fecha1;
  int cuenta = 0;
  for (int i = 0; i < reng; i++){
    if(!(vuelos[i].getFecha().getAnio() == fecha1.getAnio() && vuelos[i].getFecha().getMes() == fecha1.getMes() && vuelos[i].getFecha().getDia() == fecha1.getDia())){
      fecha1 = vuelos[i].getFecha();
      cuenta++;
    }
  }
  return cuenta;
}

void FechasTotales(Vuelos vuelos[],Fecha fechas[]){
  Fecha fecha1;
  int dia = 0;
  for (int i = 0; i < reng; i++){
    if(!(vuelos[i].getFecha().getAnio() == fecha1.getAnio() && vuelos[i].getFecha().getMes() == fecha1.getMes() && vuelos[i].getFecha().getDia() == fecha1.getDia())){
      fecha1 = vuelos[i].getFecha();
      fechas[dia] = fecha1;
      dia++;
    }
  }
}

int HoraSaturada(Fecha v, Vuelos vuelos[]) {
  int anio = v.getAnio();
  int mes = v.getMes();
  int dia = v.getDia();


  int horas[24];
  for(int i = 0; i < 24; i++) {
    horas[i] = 0;
  }

  int i = 0;

  while(!(vuelos[i].getFecha().getAnio() == anio && vuelos[i].getFecha().getMes() == mes && vuelos[i].getFecha().getDia() == dia)) {
    i++;
  }

  while(vuelos[i].getFecha().getAnio() == anio && vuelos[i].getFecha().getMes() == mes && vuelos[i].getFecha().getDia() == dia) {
    horas[vuelos[i].getFecha().getHora()] += 1;
    i++;
  }

  int mayor = 0;
  int iMayor = 0;
  for(int i = 0; i < 24; i++) {
    if(mayor < horas[i]) {
      mayor = horas[i];
      iMayor = i;
    }
  }
  return iMayor;
}

int CuentaEntrasale(string entrasale, Vuelos vuelos[]){
  int cuenta = 0;
  for (int i = 0; i < reng; i++) {
    if(vuelos[i].getLlegadaSalida() == entrasale) {
      cuenta++;
    }
  }
  return cuenta;
}

void EntrasaleTotales(string entrasale, Vuelos vuelos[], Vuelos vuelosEntrasale[]){
  int cuenta = 0;
  for (int i = 0; i < reng; i++){
    if(vuelos[i].getLlegadaSalida() == entrasale) {
      vuelosEntrasale[cuenta] = vuelos[i];
      cuenta++;
    }
  }
}

void PromedioPorHora(int total, int fechas, Vuelos vuelos[], float horas[]) {
  for(int i = 0; i < 24; i++) {
    horas[i] = 0;
  }

  for(int i = 0; i < total; i++) {
    horas[vuelos[i].getFecha().getHora()] += 1;
  }

  for(int i = 0; i < 24; i++) {
    horas[i] = horas[i]/fechas;
  }
}

void ContarAerolineas(vector<string> &aerolineas, Vuelos vuelos[]) {
  bool check;
  for(int i = 0; i < reng; i++)
  {
    check = false;
    for(int j = 0; j < aerolineas.size(); j++) {
      if(aerolineas[j] == vuelos[i].getAvion().getAerolinea()) {
        check = true;
      }
    }
    if(!check) {
      aerolineas.push_back(vuelos[i].getAvion().getAerolinea());
    }
  }
}

int PasajeroSaturado(Fecha v, Vuelos vuelos[]){
  int anio = v.getAnio();
  int mes = v.getMes();
  int dia = v.getDia();

  int suma = 0;
  int i = 0;

  while(!(vuelos[i].getFecha().getAnio() == anio && vuelos[i].getFecha().getMes() == mes && vuelos[i].getFecha().getDia() == dia)) {
    i++;
  }

  while(vuelos[i].getFecha().getAnio() == anio && vuelos[i].getFecha().getMes() == mes && vuelos[i].getFecha().getDia() == dia) {
    suma += vuelos[i].getPasajeros();
    i++;
  }
  return suma;
}

float PasajeroCapacidad(Fecha v, Vuelos vuelos[]){
  int anio = v.getAnio();
  int mes = v.getMes();
  int dia = v.getDia();

  float pasajeros;
  float capacidad;
  int i = 0;

   while(!(vuelos[i].getFecha().getAnio() == anio && vuelos[i].getFecha().getMes() == mes && vuelos[i].getFecha().getDia() == dia)) {
    i++;
   }

   while(vuelos[i].getFecha().getAnio() == anio && vuelos[i].getFecha().getMes() == mes && vuelos[i].getFecha().getDia() == dia) {
      pasajeros += vuelos[i].getPasajeros();
      capacidad += vuelos[i].getAvion().getCapacidad(); 
    i++;
  }
  return 100*(pasajeros/capacidad);
}

int main() {
  string datos[9];
  ifstream archivo;

  archivo.open("datos_vuelos.txt");

  while( archivo >> datos[0] >> datos[1] >> datos[2] >> datos[3] >> datos[4] >> datos[5] >> datos[6] >> datos[7] >> datos[8] ) {
    reng++;
  }

  archivo.close();


  Vuelos vuelos[reng];
  int i = 0;
  archivo.open("datos_vuelos.txt");

 while ( archivo >> datos[0] >> datos[1] >> datos[2] >> datos[3] >> datos[4] >> datos[5] >> datos[6] >> datos[7] >> datos[8] ) {
    Fecha fecha_temp;
    fecha_temp = FechaHora(datos[0], datos[1]);
    vuelos[i] = Vuelos(stoi(datos[7]), datos[2], datos[3], Avion(datos[6], stoi(datos[8]), datos[4]), fecha_temp);
    i++;
  }

  archivo.close();

  //Pregunta 1
  Fecha fechas[CuentaFechas(vuelos)];
  FechasTotales(vuelos, fechas);
  for(int i = 0; i < CuentaFechas(vuelos); i++) {
    cout << "Hora con la mayor cantidad de vuelos en " << fechas[i].getDia() << "/" << fechas[i].getMes() << "/"  << fechas[i].getAnio() << " es " << HoraSaturada(fechas[i], vuelos) << ":00" << endl;
  }

  cout << endl;
  //Pregunta 2 y 3
  int entra, sale;
  entra = CuentaEntrasale("A", vuelos);
  sale = CuentaEntrasale("S", vuelos);
  Vuelos vuelosEntra[CuentaEntrasale("A", vuelos)];
  EntrasaleTotales("A", vuelos, vuelosEntra);
  float horasEntra[24];
  PromedioPorHora(CuentaEntrasale("A", vuelos), CuentaFechas(vuelos), vuelosEntra, horasEntra);

  Vuelos vuelosSale[CuentaEntrasale("S", vuelos)];
  EntrasaleTotales("S", vuelos, vuelosSale);
  float horasSale[24];
  PromedioPorHora(CuentaEntrasale("S", vuelos), CuentaFechas(vuelos), vuelosSale, horasSale);

  for(int i = 0; i < 24; i++) {
    cout << "Hora " << i << " - " << horasEntra[i] << " llegadas y " << horasSale[i] << " salidas promedio." << endl;
  }

  cout << endl;

  //Pregunta 4
  vector<string> aerolineas;
  ContarAerolineas(aerolineas, vuelos);
  sort(aerolineas.begin(), aerolineas.end());
  int cantidadAeroEntra[aerolineas.size()];
  int cantidadAeroSalida[aerolineas.size()];

  for(int i = 0; i < aerolineas.size(); i++){
    cantidadAeroEntra[i] = 0;
    cantidadAeroSalida[i] = 0;
  }

  for(int i = 0; i < aerolineas.size(); i++){
    for(int j = 0; j < entra; j++){
      if(aerolineas[i] == vuelosEntra[j].getAvion().getAerolinea()){
        cantidadAeroEntra[i] += 1;
      }
    }
  }

  for(int i = 0; i < aerolineas.size(); i++){
    for(int j = 0; j < sale; j++){
      if(aerolineas[i] == vuelosSale[j].getAvion().getAerolinea()){
        cantidadAeroSalida[i] += 1;
      }
    }
  }
  
  for(int i = 0; i < aerolineas.size(); i++){
        cout << "Aerolineas " << aerolineas[i] << " - " << cantidadAeroEntra[i] << " llegadas y " << cantidadAeroSalida[i] << " salidas" << endl;
  }

  cout << endl;

  //Pregunta 5
  for(int i = 0; i < CuentaFechas(vuelos); i++) {
    cout << "El numero de pasajeros atendidos en " << fechas[i].getDia() << "/" << fechas[i].getMes() << "/"  << fechas[i].getAnio() << " es " << PasajeroSaturado(fechas[i], vuelos) << endl;
  }

  cout << endl;

  //Pregunta 6
  for(int i = 0; i < CuentaFechas(vuelos); i++) {
   cout << "El porcentaje promedio de pasajeros vs capacidad en " << fechas[i].getDia() << "/" << fechas[i].getMes() << "/"  << fechas[i].getAnio() << " es " << PasajeroCapacidad(fechas[i], vuelos) << "%" << endl;
  }

  cout << endl;
  
  return 0;
}
