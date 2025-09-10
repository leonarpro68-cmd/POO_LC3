#pragma once
#include "Sensor.h"

ref class NodoArbol {
private:
    Sensor^ sensor;
    NodoArbol^ izquierda;
    NodoArbol^ derecha;

public:
    NodoArbol(int id, String^ nombre, String^ tipo, String^ zona) {
        this->sensor = gcnew Sensor(id, nombre, tipo, zona);
        this->izquierda = nullptr;
        this->derecha = nullptr;
    }

    Sensor^ getSensor() {
        return this->sensor;
    }

    void setSensor(Sensor^ nuevoSensor) {
        this->sensor = nuevoSensor;
    }

    NodoArbol^ getIzquierda() {
        return this->izquierda;
    }

    void setIzquierda(NodoArbol^ nuevoIzquierda) {
        this->izquierda = nuevoIzquierda;
    }

    NodoArbol^ getDerecha() {
        return this->derecha;
    }

    void setDerecha(NodoArbol^ nuevoDerecha) {
        this->derecha = nuevoDerecha;
    }

    void imprimirNodo() {
        this->sensor->imprimirSensor();
    }

    String^ obtenerInfoResumida() {
        return this->sensor->obtenerInfoResumida();
    }
};