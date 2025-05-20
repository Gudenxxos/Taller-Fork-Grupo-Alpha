/***************************************
-Pontificia Universidad Javeriana
-Nombres: Guden Silva
-Clase: Sistemas Operativos
-Fecha: 2025-05-20
-Tema: OpenMP
-Conclusiones: 	El programa hace un buen uso de OpenMP, estableciendo la cantidad de
		hilos a utlizar.

		En un primer momento se establece el tamano de ambas matrices y se inicializan

		Se hace un llamado a MultiMatriz que es la función encargada de la multiplicación
		de las dos matrices utilizando OpenMP

		Se definen correctamente las directivas con el compilador usando #pragma omp parallel

		Dependiendo de lo que se esté haciendo se añade a esta directa private(...) o for

		Se utliza private(...) para asignar variables privadas para cada hilo, en este caso
		Suma, pA y pB. Posteriormente se utiliza for para definir el ciclo que hace cada hilo
		para la multiplicación de la matriz.

-Observaciones: Si bien, está bien definido el número de hilos que se quiere utilizar, se debería
		tener en cuenta el total de hilos posible para el computador, de tal manera que al asignar
		el número de hilos, este no sobrepase el total de hilos de la máquina. 
**************************************/

#include "mmInterfazOpenMP.h"

/*
 * Función principal que:
 * 1. Valida argumentos de entrada (tamaño y número de hilos)
 * 2. Reserva memoria e inicializa matrices
 * 3. Realiza la multiplicación de matrices en paralelo 
 * 4. Mide el tiempo de ejecución
 * 5. Imprime las matrices si son pequeñas
 */
int main(int argc, char *argv[]){
	if(argc < 3){
		printf("\n Use: $./clasicaOpenMP SIZE Hilos \n\n");
		exit(0);
	}

	int N = atoi(argv[1]);  // Dimensión de la matriz
	int TH = atoi(argv[2]); // Número de hilos a utilizar

	// Reservar memoria para matrices A, B y C 
	size_t *matrixA  = (size_t *)calloc(N*N, sizeof(size_t));
	size_t *matrixB  = (size_t *)calloc(N*N, sizeof(size_t));
	size_t *matrixC  = (size_t *)calloc(N*N, sizeof(size_t));

	srand(time(NULL));      // Inicializa semilla para números aleatorios

	omp_set_num_threads(TH); // Establece número de hilos a usar

	iniMatrix(matrixA, matrixB, N); // Inicializa las matrices A y B

	impMatrix(matrixA, N);  // Imprime matriz A si es pequeña
	impMatrix(matrixB, N);  // Imprime matriz B si es pequeña

	InicioMuestra();              // Inicia cronómetro
	multiMatrix(matrixA, matrixB, matrixC, N); // Multiplica matrices
	FinMuestra();                 // Finaliza cronómetro e imprime el tiempo

	impMatrix(matrixC, N);        // Imprime matriz resultado si es pequeña

	free(matrixA);                // Libera memoria asignada a matriz A
	free(matrixB);                // Libera memoria asignada a matriz B
	free(matrixC);                // Libera memoria asignada a matriz C

	return 0;
}
