#ifndef Fecha_h
#define Fecha_h

using namespace std;

class Fecha{
private:
    int dia;
    int mes;
    int anio;
    int hora;
    int minuto;
public:
    Fecha();
    Fecha(int, int, int, int, int);
    void setDia(int);
    void setMes(int);
    void setAnio(int);
    void setHora(int);
    void setMinuto(int);
    int getDia();
    int getMes();
    int getAnio();
    int getHora();
    int getMinuto();
    string datos();
};

Fecha::Fecha(){
    dia = 0;
    mes = 0;
    anio = 0;
    hora = 0;
    minuto = 0;
}
Fecha::Fecha(int dia, int mes, int anio, int hora, int minuto){
    this->dia = dia;
    this->mes = mes;
    this->anio = anio;
    this->hora = hora;
    this->minuto = minuto;
}
void Fecha::setDia(int dia){
    this->dia = dia;
}
void Fecha::setMes(int mes){
    this->mes = mes;
}
void Fecha::setAnio(int anio){
    this->anio = anio;
}
void Fecha::setHora(int hora){
    this->hora = hora;
}
void Fecha::setMinuto(int minuto){
    this->minuto = minuto;
}
int Fecha::getDia(){
    return dia;
}
int Fecha::getMes(){
    return mes;
}
int Fecha::getAnio(){
    return anio;
}
int Fecha::getHora(){
    return hora;
}
int Fecha::getMinuto(){
    return minuto;
}
string Fecha::datos(){
    string laLas;
    if(hora == 1){
        laLas = "la ";
    }
    else{
        laLas = "las ";
    }

    return  to_string(anio) + "/" + to_string(mes) + "/" + to_string(dia)
          + " a " + laLas + to_string(hora) + ":" + to_string(minuto) + ".";
}

#endif
