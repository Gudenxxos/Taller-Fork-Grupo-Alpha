/********************************************
* PONTIFICIA UNIVERSIDAD JAVERIANA
* AUTOR: Guden Silva
* Fecha: 13 de mayo de 2025
* Sistemas Operativos
* Tema: OpenMP
* Descripción: Se hace la integración con OpenMP y se crean hilos con la máxima cantida disponibles
*********************************************/
#include <stdlib.h>
#include <stdio.h>
#include <omp.h> // Librería omp

int main(int argc, char * argv[]){
	printf("OpenMP ejecutando con %d hilos \n", omp_get_max_threads()); // Imprime la máxima cantidad de hilos
									    // Posible

#pragma omp parallel // Directiva al compilador que indica que lo siguiente se va a hacer en todos los hilos
{
	printf("Hello World desde el thread %d\n", omp_get_thread_num()); //Imprime el hilo en el que está
}
	return 0;
}
