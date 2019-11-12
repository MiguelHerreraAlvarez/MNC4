#include "tools.h"
#include <iostream>

void tools::print_matrix(double matrix[], int m, int n)
{
	for (auto i = 0; i < n*m; i++)
	{
		std::cout <<  matrix[i] << ((i + 1) % m == 0 ? '\n' : ' ');
	}
}

double tools::diagonal_product(double matrix[], int m, int n) {
	double res = 0;
	for (int i = 0; i < m; i++)
	{
		res += matrix[i * n + i];
	}
	return res;
}