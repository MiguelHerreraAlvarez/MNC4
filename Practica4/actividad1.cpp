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
	double matrix[N * M] = { 4.3466,   1.9819,   9.4501,   6.3484,   6.2670,   3.2423,
							 3.1200,   4.9959,   2.0597,   7.4376,   7.4855,   5.8703,
							 9.1469,   2.2650,   2.7794,   3.8528,   4.7609,   9.2481,
							 5.9549,   9.6416,   9.4840,   7.1949,   8.6092,   6.8124,
							 4.7680,   6.9788,   5.4866,   1.9240,   9.3987,   6.4336,
							 3.2699,   7.3528,   9.8925,   8.4837,   4.5013,   4.8108 };
	
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