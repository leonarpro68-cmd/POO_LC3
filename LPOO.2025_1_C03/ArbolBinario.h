#pragma once
#include "NodoArbol.h"

ref class ArbolBinario {
private:
    NodoArbol^ raiz;

    NodoArbol^ InsertarRecursivo(NodoArbol^ nodo, int id, String^ nombre, String^ tipo, String^ zona) {
        if (nodo == nullptr) {
            return gcnew NodoArbol(id, nombre, tipo, zona);
        }

        if (id < nodo->getSensor()->getId()) {
            nodo->setIzquierda(InsertarRecursivo(nodo->getIzquierda(), id, nombre, tipo, zona));
        }
        else if (id > nodo->getSensor()->getId()) {
            nodo->setDerecha(InsertarRecursivo(nodo->getDerecha(), id, nombre, tipo, zona));
        }
        else {
            // ID duplicado (actualizar datos)
            nodo->getSensor()->setNombre(nombre);
            nodo->getSensor()->setTipo(tipo);
            nodo->getSensor()->setZona(zona);
        }

        return nodo;
    }

    NodoArbol^ BuscarRecursivo(NodoArbol^ nodo, int id) {
        if (nodo == nullptr || nodo->getSensor()->getId() == id) {
            return nodo;
        }

        if (id < nodo->getSensor()->getId()) {
            return BuscarRecursivo(nodo->getIzquierda(), id);
        }
        else {
            return BuscarRecursivo(nodo->getDerecha(), id);
        }
    }

    void RecorrerEnOrdenRecursivo(NodoArbol^ nodo) {
        if (nodo != nullptr) {
            RecorrerEnOrdenRecursivo(nodo->getIzquierda());
            Console::WriteLine(nodo->obtenerInfoResumida());
            RecorrerEnOrdenRecursivo(nodo->getDerecha());
        }
    }

public:
    ArbolBinario() {
        this->raiz = nullptr;
    }

    NodoArbol^ getRaiz() {
        return this->raiz;
    }

    void setRaiz(NodoArbol^ nuevaRaiz) {
        this->raiz = nuevaRaiz;
    }

    bool EsVacio() {
        return this->raiz == nullptr;
    }

    void Insertar(int id, String^ nombre, String^ tipo, String^ zona) {
        this->setRaiz(InsertarRecursivo(this->getRaiz(), id, nombre, tipo, zona));
    }

    NodoArbol^ Buscar(int id) {
        return BuscarRecursivo(this->getRaiz(), id);
    }

    void MostrarEnOrden() {
        if (this->EsVacio()) {
            Console::WriteLine("No hay sensores registrados.");
            return;
        }
        Console::WriteLine("Sensores registrados (in-order):");
        RecorrerEnOrdenRecursivo(this->getRaiz());
    }
};