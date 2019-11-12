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

	
	double matrixa[N * M] = { 41.6180,   99.0991,    5.2742,   93.3009,   31.2564,   94.9891,
							  67.3498,   91.7177,   24.5655,   11.1171,   33.6123,   69.9333,
							  97.3775,   66.1600,   92.1510,   56.8528,   19.6738,   11.4994,
							  72.1876,   72.1499,   54.5531,   48.0483,   82.4479,   14.3707,
							  55.1804,   11.6700,   38.0457,   49.0051,   65.6391,   74.6580,
							  46.6574,   85.6328,   41.7075,   50.4176,   73.6476,   60.3488 };
	
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