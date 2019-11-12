#include "actividad1.h"
#include "tools.h"
#include <iostream>
#include <mkl.h>

#define N 6
#define M 6
#define LAYOUT LAPACK_ROW_MAJOR
#define TRANS  'N'

int actividad1::execute()
{
	double matrix[N * M] = { 41.6180,   99.0991,    5.2742,   93.3009,   31.2564,   94.9891,
						     67.3498,   91.7177,   24.5655,   11.1171,   33.6123,   69.9333,
						     97.3775,   66.1600,   92.1510,   56.8528,   19.6738,   11.4994,
						     72.1876,   72.1499,   54.5531,   48.0483,   82.4479,   14.3707,
						     55.1804,   11.6700,   38.0457,   49.0051,   65.6391,   74.6580,
						     46.6574,   85.6328,   41.7075,   50.4176,   73.6476,   60.3488 };
	
	double identity[N * M] = { 1, 0, 0, 0, 0, 0,
							   0, 1, 0, 0, 0, 0,
							   0, 0, 1, 0, 0, 0,
							   0, 0, 0, 1, 0, 0,
							   0, 0, 0, 0, 1, 0,
							   0, 0, 0, 0, 0, 1 };
	
	int* piv = (int*)mkl_malloc(N * sizeof(int), 32);

	std::cout << "\nMatriz Inicial" << '\n';
	tools::print_matrix(matrix, M, N);
	LAPACKE_dgetrf(LAYOUT, M, N, matrix, M, piv);
	std::cout << "\nMatriz Factorizada" << '\n';
	tools::print_matrix(matrix, M, N);
	std::cout << "\nVector de Pivotacion" << '\n';
	
	for (int i = 0; i < N; ++i)
	{
		std::cout << piv[i] << '\t';
	}
	
	std::cout << '\n';
	std::cout << "\nDeterminante" << '\n';
	std::cout << (tools::diagonal_product(matrix, M, N))*tools::detp(piv, N) << '\n';
	LAPACKE_dgetrs(LAYOUT, TRANS, N, N, matrix, M, piv, identity, M);
	std::cout << "\nMatriz Inversa por AX=B" << '\n';
	tools::print_matrix(identity, M, N);
	std::cout << "\nMatriz Inversa por dgetri" << '\n';
	LAPACKE_dgetri(LAYOUT, N, matrix, M, piv);
	tools::print_matrix(matrix, M, N);

	return 0;
}