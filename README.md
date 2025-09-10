# Sistema de Supervisión de Sensores con Árbol Binario de Búsqueda (BST)

## Descripción
Este proyecto implementa un sistema de gestión para sensores industriales utilizando un Árbol Binario de Búsqueda (BST) en C++/CLI. El sistema permite registrar, buscar y visualizar sensores ordenados por su ID único, optimizando el acceso y manejo de datos en entornos industriales.

## Características Principales
- **Registro de sensores** con:
  - ID único numérico
  - Nombre descriptivo
  - Tipo (temperatura, presión, humedad, etc.)
  - Zona de instalación
- **Búsqueda eficiente** por ID
- **Visualización ordenada** mediante recorrido in-order
- **Validación de datos**:
  - IDs no duplicados
  - Campos obligatorios
- **Interfaz de consola** interactiva

## Estructura del Proyecto
SistemaSensoresBST/
├── Sensor.h # Clase Sensor con atributos y métodos
├── NodoArbol.h # Nodo del BST con sensor y punteros
├── ArbolBinario.h # Implementación del BST
├── main.cpp # Programa principal con menú interactivo
└── README.md # Este archivo

## Requisitos
- Compilador de C++/CLI (Visual Studio recomendado)
- .NET Framework

## Instrucciones de Uso
1. **Compilación**:
   ```bash
   cl /clr main.cpp
2. **Ejecución**:
   SistemaSensoresBST.exe
3. **Opciones del menú**
   1. Registrar nuevo sensor
   2. Buscar sensor por ID
   3. Mostrar sensores en orden
   4. Salir

##Ejemplo de Ejecución
=== SISTEMA DE SUPERVISIÓN DE SENSORES ===
1. Registrar nuevo sensor
2. Buscar sensor por ID
3. Mostrar sensores en orden
4. Salir
Seleccione una opción: 1
Ingrese ID del sensor: 20
Nombre: Sensor T1
Tipo: Temperatura
Zona: Zona A
>> Sensor registrado correctamente.

[Opción 3 muestra:]
Sensores registrados (in-order):
[20] Sensor T1 (Temperatura - Zona A)
   
