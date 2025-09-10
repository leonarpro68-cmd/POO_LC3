#include <iostream>
#include "ArbolBinario.h"

using namespace System;

void MostrarMenu() {
    Console::WriteLine("=== SISTEMA DE SUPERVISION DE SENSORES ===");
    Console::WriteLine("1. Registrar nuevo sensor");
    Console::WriteLine("2. Buscar sensor por ID");
    Console::WriteLine("3. Mostrar sensores en orden");
    Console::WriteLine("4. Salir");
    Console::Write("Seleccione una opcion: ");
}

String^ SolicitarDato(String^ mensaje) {
    Console::Write(mensaje);
    String^ entrada = Console::ReadLine();
    while (entrada->Trim()->Length == 0) {
        Console::WriteLine("Error: Este campo no puede estar vacio.");
        Console::Write(mensaje);
        entrada = Console::ReadLine();
    }
    return entrada;
}

int main() {
    ArbolBinario^ arbol = gcnew ArbolBinario();
    int opcion, id;
    Console::Clear(); //Limpiamos la pantalla de la consola

    do {
        MostrarMenu();
        opcion = Convert::ToInt32(Console::ReadLine());

        switch (opcion) {
        case 1: // Registrar nuevo sensor
        {
            Console::Write("Ingrese ID del sensor: ");
            id = Convert::ToInt32(Console::ReadLine());

            if (arbol->Buscar(id) != nullptr) {
                Console::WriteLine(">> Error: Ya existe un sensor con ese ID.");
                Console::ReadKey();
                break;
            }

            String^ nombre = SolicitarDato("Nombre: ");
            String^ tipo = SolicitarDato("Tipo: ");
            String^ zona = SolicitarDato("Zona: ");

            arbol->Insertar(id, nombre, tipo, zona);
            Console::WriteLine(">> Sensor registrado correctamente. Presione [Enter] para continuar");
            Console::ReadKey();
            break;
        }

        case 2: // Buscar sensor por ID
        {
            Console::Write("Ingrese ID a buscar: ");
            id = Convert::ToInt32(Console::ReadLine());

            NodoArbol^ encontrado = arbol->Buscar(id);
            if (encontrado != nullptr) {
                Console::WriteLine(">> Sensor encontrado:");
                encontrado->imprimirNodo();
            }
            else {
                Console::WriteLine(">> Sensor no encontrado.");
            }
            Console::WriteLine("Presione [Enter] para continuar");
            Console::ReadKey();
            break;
        }

        case 3: // Mostrar sensores en orden
            arbol->MostrarEnOrden();
            Console::WriteLine("\nPresione cualquier tecla para continuar...");
            Console::ReadKey();
            break;

        case 4: // Salir
            Console::WriteLine(">> Cerrando sistema...");
            break;

        default:
            Console::WriteLine("Opcion no valida. Presione [Enter] para intentar nuevamente.");
            Console::ReadKey();
            break;
        }

    } while (opcion != 4);

    return 0;
}