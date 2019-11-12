#include "actividad2.h"
#include "tools.h"
#include <iostream>
#include <mkl.h>
#include <random>

#define N 6
#define M 6
#define LAYOUT LAPACK_ROW_MAJOR

int actividad2::execute(){
	std::default_random_engine generador;
	std::normal_distribution<double> aleatorio(0.0, 1.0);

	
	double matrixa[N * M] = { 4.3466,   1.9819,   9.4501,   6.3484,   6.2670,   3.2423,
							  3.1200,   4.9959,   2.0597,   7.4376,   7.4855,   5.8703,
							  9.1469,   2.2650,   2.7794,   3.8528,   4.7609,   9.2481,
							  5.9549,   9.6416,   9.4840,   7.1949,   8.6092,   6.8124,
							  4.7680,   6.9788,   5.4866,   1.9240,   9.3987,   6.4336,
							  3.2699,   7.3528,   9.8925,   8.4837,   4.5013,   4.8108 };
	
	double matrixb[N * M] = { 1, 0, 0, 0, 0, 0,
							  0, 1, 0, 0, 0, 0,
							  0, 0, 1, 0, 0, 0,
							  0, 0, 0, 1, 0, 0,
							  0, 0, 0, 0, 1, 0,
							  0, 0, 0, 0, 0, 1 };
	
	int* piv = (int*)mkl_malloc(N * sizeof(int), 32);

	std::cout << "Matriz Original" << '\n';
	tools::print_matrix(matrixa, M, N);
	LAPACKE_dgesv(LAYOUT, N, N, matrixa, M, piv, matrixb, M);
	std::cout << "Factorizacion LU" << '\n';
	tools::print_matrix(matrixa, M, N);
	std::cout << "Matriz Inversa" << '\n';
	tools::print_matrix(matrixb, M, N);

	double* matrix2 = (double*)mkl_malloc(M * N * sizeof(double), 32);
	for (int i = 0; i < M*N; ++i)
	{
		matrix2[i*N + i] = aleatorio(generador);
	}

	tools::print_matrix(matrix2, M, N);
	return 0;
}