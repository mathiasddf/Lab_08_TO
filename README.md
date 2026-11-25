# Laboratorio 08: Patrón de Diseño Factory y Abstract Factory en C++

**Universidad:** Universidad Nacional de San Agustín de Arequipa (UNSA)  
**Escuela Profesional:** Ingeniería de Sistemas  
**Asignatura:** Tecnología de Objetos (2026-B)  
**Docente:** MBA Mg. Ing. Rene Alonso Nieto Valencia  

## Integrantes
- Ccahua Chise Elizabeth Karina
- Navarro Quispe Henry Alex
- Davila Flores Mathias Dario

## Estructura del Repositorio

| Archivo | Descripción |
| :--- | :--- |
| `ejercicio1_recetas.cpp` | Fábrica de recetas de cocina aplicando el patrón **Factory** (`Receta`, `RecetaFactory`) con lugar de origen, ingredientes, dificultad, tiempo, porciones y costo estimado (Rocoto Relleno, Ceviche Clásico y Pizza Napolitana). |
| `ejercicio2_gui.cpp` | Implementación de controles gráficos multiplataforma (`Button` y `CheckBox`) mediante el patrón **Abstract Factory** (`GUIFactory`) para Windows, Mac y Linux. |

## Compilación y Ejecución

Requiere `g++` con soporte para **C++17**:

```bash
# Ejercicio 1
g++ -std=c++17 -Wall ejercicio1_recetas.cpp -o ejercicio1 && ./ejercicio1

# Ejercicio 2
g++ -std=c++17 -Wall ejercicio2_gui.cpp -o ejercicio2 && ./ejercicio2
```
