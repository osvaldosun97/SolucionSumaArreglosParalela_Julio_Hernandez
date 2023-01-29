// SolucionSumaArreglosParalela_Julio_Hernandez.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <iostream>

#include <omp.h>

#define N 1000
#define chunk 120
#define mostrar 15

void imprimeArreglo(float* d);
void imprimeArregloMayorA(float* d);

int main()
{
	std::cout << "Sumando Arreglos en Paralelo!" << std::endl;
	std::cout << std::endl;

	float a[N], b[N], c[N];

	int i;

	for (i = 0; i < N; i++) {
		a[i] = i * 10;
		b[i] = (i + 3) * 3.7;
	}

	int pedazos = chunk;

#pragma omp parallel for \
    shared(a, b, c, pedazos) private(i) \
    schedule(static, pedazos)

	for (i = 0; i < N; i++)
		c[i] = a[i] + b[i];


	if (N <= 1000)
	{
		std::cout << "Imprimiendo los primeros " << mostrar << "valores del arreglo a: " << std::endl;
		imprimeArreglo(a);
		std::cout << "Imprimiendo los primeros " << mostrar << "valores del arreglo b: " << std::endl;
		imprimeArreglo(b);
		std::cout << "Imprimiendo los primeros " << mostrar << "valores del arreglo c: " << std::endl;
		imprimeArreglo(c);
	}
	else {

		int nMinusTen = (N - mostrar) - 1;

		if (nMinusTen > 0) {
			std::cout << "Sumando Arreglos Mayores a 1000 elementos!" << std::endl;
			std::cout << std::endl;

			std::cout << "Imprimiendo los primeros " << mostrar << " y ultimos " << mostrar << " valores del arreglo a: " << std::endl;
			std::cout << std::endl;
			imprimeArregloMayorA(a);
			std::cout << "Imprimiendo los primeros " << mostrar << " y ultimos " << mostrar << " valores del arreglo b: " << std::endl;
			std::cout << std::endl;
			imprimeArregloMayorA(b);
			std::cout << "Imprimiendo los primeros " << mostrar << " y ultimos " << mostrar << " valores del arreglo c: " << std::endl;
			std::cout << std::endl;
			imprimeArregloMayorA(c);
		}
		else {
			std::cout << "Error verificar el numero de elementos!" << std::endl;
		}
	}
}

void imprimeArreglo(float* d) {

	for (int i = 0; i < mostrar; i++) {

		if (i == mostrar - 1)
			std::cout << d[i];
		else
			std::cout << d[i] << " - ";

	}

	std::cout << std::endl;
}

void imprimeArregloMayorA(float* d) {

	for (int i = 0; i < mostrar; i++) {

		if (i == mostrar - 1)
			std::cout << d[i];
		else
			std::cout << d[i] << " - ";

	}

	std::cout << " | ";

	int nMinusTen = (N - mostrar) - 1;

	for (int i = 0; i < mostrar; i++) {

		if (i == mostrar - 1)
			std::cout << d[nMinusTen];
		else
			std::cout << d[nMinusTen] << " - ";

		nMinusTen++;

	}

	std::cout << std::endl;
	std::cout << std::endl;
}

// Ejecutar programa: Ctrl + F5 o menú Depurar > Iniciar sin depurar
// Depurar programa: F5 o menú Depurar > Iniciar depuración

// Sugerencias para primeros pasos: 1. Use la ventana del Explorador de soluciones para agregar y administrar archivos
//   2. Use la ventana de Team Explorer para conectar con el control de código fuente
//   3. Use la ventana de salida para ver la salida de compilación y otros mensajes
//   4. Use la ventana Lista de errores para ver los errores
//   5. Vaya a Proyecto > Agregar nuevo elemento para crear nuevos archivos de código, o a Proyecto > Agregar elemento existente para agregar archivos de código existentes al proyecto
//   6. En el futuro, para volver a abrir este proyecto, vaya a Archivo > Abrir > Proyecto y seleccione el archivo .sln
