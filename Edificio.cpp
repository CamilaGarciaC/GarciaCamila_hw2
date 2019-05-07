#include <iostream>
#include <cmath>
#include <fstream>
#include <vector>

using namespace std;

//Se declaran los parametros.
const double m = 1000.0;
const double k = 2000.0;
const double gama = 0.0;
const double h = 0.1;

//Funciones para el metodo de runge kutta
double du1dt( double t, double u1, double u2, double u3, double v1, double v2, double v3){
	return v1;
}
