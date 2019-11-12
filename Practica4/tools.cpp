#include "Tools.h"
#include <iostream>

void tools::print_matrix(double matrix[], int m, int n)
{
	for (auto i = 0; i < n*m; i++)
	{
		std::cout <<  matrix[i] << ((i + 1) % m == 0 ? '\n' : ' ');
	}
}
