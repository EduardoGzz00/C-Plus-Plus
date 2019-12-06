#ifndef Avion_h
#define Avion_h

class Avion {
private:
  string avionId;
  int capacidad;
  string aerolinea;
public:
  Avion();
  Avion(string avionId, int capacidad, string aerolinea);
  void setId(string avionId);
  void setCapacidad(int capacidad);
  void setAerolinea(string aerolinea);
  string getId();
  int getCapacidad();
  string getAerolinea();
};

Avion::Avion() {
  avionId = "1";
  capacidad = 100;
  aerolinea = "Aeromexico";
}

Avion::Avion(string avionId, int capacidad, string aerolinea) {
  this->avionId = avionId;
  this->capacidad = capacidad;
  this->aerolinea = aerolinea;
}

void Avion::setId(string avionId) {
  this->avionId = avionId;
}

void Avion::setCapacidad(int capacidad) {
  this->capacidad = capacidad;
}

void Avion::setAerolinea(string aerolinea) {
  this->aerolinea = aerolinea;
}

string Avion::getId() {
  return avionId;
}

int Avion::getCapacidad() {
  return capacidad;
}

string Avion::getAerolinea() {
  return aerolinea;
}

#endif
