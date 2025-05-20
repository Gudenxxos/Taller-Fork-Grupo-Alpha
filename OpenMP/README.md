# Multiplicación de Matrices con OpenMP

Este proyecto implementa la multiplicación de matrices cuadradas utilizando paralelización con OpenMP en lenguaje C. Es parte de una práctica académica para la clase de **Sistemas Operativos** en la **Pontificia Universidad Javeriana**.

## Archivos

- `mmClasicaOpenMP.c`: Archivo principal que gestiona la ejecución del programa. Toma el tamaño de la matriz y el número de hilos como argumentos, inicializa las matrices, realiza la multiplicación paralela y mide el tiempo de ejecución.
- `mmInterfazOpenMP.c`: Contiene las funciones auxiliares necesarias para inicializar matrices, imprimirlas, medir el tiempo y realizar la multiplicación usando directivas de OpenMP.
- `mmInterfazOpenMP.h`: Archivo de cabecera que declara las funciones usadas en el proyecto y gestiona las bibliotecas necesarias.

## Requisitos

- Compilador compatible con OpenMP (por ejemplo, `gcc`).
- Sistema Unix/Linux recomendado.

## Compilación

Usa el siguiente comando para compilar el programa:

```bash
gcc mmClasicaOpenMP.c mmInterfazOpenMP.c -o clasicaOpenMP -fopenmp
