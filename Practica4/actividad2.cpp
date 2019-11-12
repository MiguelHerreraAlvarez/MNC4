#include "actividad2.h"
#include "tools.h"
#include <iostream>
#include <mkl.h>
#include <random>

#define N 3
#define M 3
#define LAYOUT LAPACK_ROW_MAJOR

int actividad2::execute(){
	std::default_random_engine generador;
	std::normal_distribution<double> aleatorio(0.0, 1.0);

	
    double matrixa[N * M] = { 1, -1, 0, 0, 1, 0, 2, 0, 1 };
	double matrixb[N * M] = { 1, 0, 0, 0, 1, 0, 0, 0, 1 };
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