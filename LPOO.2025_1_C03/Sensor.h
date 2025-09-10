#pragma once
#pragma once
using namespace System;

ref class Sensor {
private:
    int id;
    String^ nombre;
    String^ tipo;
    String^ zona;

public:
    Sensor(int id, String^ nombre, String^ tipo, String^ zona) {
        this->id = id;
        this->nombre = nombre;
        this->tipo = tipo;
        this->zona = zona;
    }

    int getId() {
        return this->id;
    }

    void setId(int nuevoId) {
        this->id = nuevoId;
    }

    String^ getNombre() {
        return this->nombre;
    }

    void setNombre(String^ nuevoNombre) {
        this->nombre = nuevoNombre;
    }

    String^ getTipo() {
        return this->tipo;
    }

    void setTipo(String^ nuevoTipo) {
        this->tipo = nuevoTipo;
    }

    String^ getZona() {
        return this->zona;
    }

    void setZona(String^ nuevaZona) {
        this->zona = nuevaZona;
    }

    void imprimirSensor() {
        Console::WriteLine("ID: " + this->id);
        Console::WriteLine("Nombre: " + this->nombre);
        Console::WriteLine("Tipo: " + this->tipo);
        Console::WriteLine("Zona: " + this->zona);
    }

    String^ obtenerInfoResumida() {
        return String::Format("[{0}] {1} ({2} - {3})",
            this->id, this->nombre, this->tipo, this->zona);
    }
};