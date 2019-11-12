#include "actividad1.h"
#include "tools.h"
#include <iostream>
#include <mkl.h>

#define N 3
#define M 3
#define layout LAPACK_ROW_MAJOR

double diagonal_product(double matrix[], int m, int n) {
	double res = 0;
	for (int i = 0; i < m; i++)
	{
		res += matrix[i * n + i];
	}
	return res;
}

int actividad1::execute()
{
	double matrix[N * M] = { 3, 2, 1, 6, 5, 4, 9, 8, 7 };
	int piv[N] = { 0, 0, 0 };

	std::cout << "Matriz Inicial" << '\n';
	printmatrix(matrix, M, N);
	LAPACKE_dgetrf(layout, M, N, matrix, M, piv);
	std::cout << "Matriz Factorizada" << '\n';
	printmatrix(matrix, M, N);
	std::cout << "Vector de Pivotacion" << '\n';
	for (auto var : piv)
	{
		std::cout << var << ' ';
	}
	std::cout << '\n' << diagonal_product(matrix, M, N);
}