// Practica4.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <iostream>
#include "Actividad1.h"
#include "Actividad2.h"
#include "Actividad3.h"
#include "Tools.h"
#define N 3
#define M 3
int main()
{
	double matrix[N * M] = { 1,2,3,4,5,6,7,8,9 };
	tools::print_matrix(matrix, M, N);
	/*
	std::cout << "Actividad 1\n";
	actividad1::execute();
	std::cout << "\n\nActividad 2\n";
	actividad2::execute();
	std::cout << "\n\nActividad 3\n";
	actividad3::execute();
	*/
}
