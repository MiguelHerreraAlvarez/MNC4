#include "actividad2.h"
#include "tools.h"
#include <iostream>
#include <mkl.h>

#define N 3
#define M 3
#define layout LAPACK_ROW_MAJOR

int actividad2::execute(){
    double matrix[N * M] = { 3, 2, 1, 6, 5, 4, 9, 8, 7 };
	int piv[N] = { 0, 0, 0 };

    LAPACKE_dgesv();
}