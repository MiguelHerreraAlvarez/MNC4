#include "actividad1.h"
#include "tools.h"
#include <iostream>
#include <mkl.h>

#define N 3
#define M 3
#define layout LAPACK_ROW_MAJOR
#define trans  'N'
int actividad1::execute()
{
	double matrix[N * M] = { 1, -1, 0, 0, 1, 0, 2, 0, 1 };
	double identity[N * M] = { 1, 0, 0, 0, 1, 0, 0, 0, 1 };
	int* piv = (int*)mkl_malloc(N * sizeof(int), 32);

	std::cout << "Matriz Inicial" << '\n';
	tools::print_matrix(matrix, M, N);
	LAPACKE_dgetrf(layout, M, N, matrix, M, piv);
	std::cout << "Matriz Factorizada" << '\n';
	tools::print_matrix(matrix, M, N);
	std::cout << "Vector de Pivotacion" << '\n';
	for (int i = 0; i < N; ++i)
	{
		std::cout << piv[i] << '\t';
	}
	std::cout << '\n';
	std::cout << "Determinante" << '\n';
	std::cout << (tools::diagonal_product(matrix, M, N))*tools::detp(piv, N) << '\n';
	LAPACKE_dgetrs(layout, trans, N, N, matrix, M, piv, identity, M);
	std::cout << "Matriz Inversa por AX=B" << '\n';
	tools::print_matrix(identity, M, N);
	std::cout << "Matriz Inversa por dgetri" << '\n';
	LAPACKE_dgetri(layout, N, matrix, M, piv);
	tools::print_matrix(matrix, M, N);

	return 0;
}