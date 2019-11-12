#include "tools.h"
#include <iostream>

void tools::print_matrix(double matrix[], int m, int n)
{
	for (auto i = 0; i < n*m; i++)
	{
		std::cout <<  matrix[i] << ((i + 1) % m == 0 ? '\n' : '\t');
	}
}

double tools::diagonal_product(double matrix[], int m, int n) {
	double res = 1;
	for (int i = 0; i < m; i++)
	{
		res *= matrix[i * n + i];
	}
	return res;
}

int tools::detp(int piv[], int length)
{
	int j;
	int detp = 1;
	
	for (j = 0; j < length; j++) {
		if (j + 1 != piv[j]) {
			// j+1 : following feedback of ead : ipiv is from Fortran, hence starts at 1.
			// hey ! This is a transpose !
			detp = -detp;
		}
	}
	
	return detp;
}