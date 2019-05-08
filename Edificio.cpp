#include <iostream>
#include <cmath>
//#include <fstream>
//#include <vector>

using namespace std;


//Se declaran los parametros.
const double m = 1000.0;
const double k = 2000.0;
const double gama = 0.0;
const double h = 0.1;

//Funciones de derivada para el metodo de runge kutta
double du1dt( double t, double u1, double u2, double u3, double v1, double v2, double v3){
	return v1;
}

double du2dt( double t, double u1, double u2, double u3, double v1, double v2, double v3){
	return v2;
}

double du3dt( double t, double u1, double u2, double u3, double v1, double v2, double v3){
	return v3;
}

//Se dan las ecuaciones diferenciales de segundo orden dadas en el ejercicio

double dv1dt( double t, double u1, double u2, double u3, double v1, double v2, double v3, double w){
	return 1.0/m*(-gama*v1 - 2*k*u1 + k*u2 + sin(w*t) );
}

double dv2dt( double t, double u1, double u2, double u3, double v1, double v2, double v3){
	return 1.0/m*(-gama*v2 + k*u1 - 2*k*u2 + k*u3 );
}

double dv3dt( double t, double u1, double u2, double u3, double v1, double v2, double v3){
	return 1.0/m*(-gama*v3 + k*u2 - k*u3 );
}

//Metodo runge kutta
void rk4_step( double t, double &u1, double &u2, double &u3, double &v1, double &v2, double &v3, double w ){
	double k[4][6];

	k[0][0] = h*du1dt( t, u1, u2, u3, v1, v2, v3 );
	k[0][1] = h*du2dt( t, u1, u2, u3, v1, v2, v3 );
	k[0][2] = h*du3dt( t, u1, u2, u3, v1, v2, v3 );
	k[0][3] = h*dv1dt( t, u1, u2, u3, v1, v2, v3, w );
	k[0][4] = h*dv2dt( t, u1, u2, u3, v1, v2, v3 );
	k[0][5] = h*dv3dt( t, u1, u2, u3, v1, v2, v3 );

	k[1][0] = h*du1dt( t+0.5*h, u1+0.5*k[0][0], u2+0.5*k[0][1], u3+0.5*k[0][2], v1+0.5*k[0][3], v2+0.5*k[0][4], v3+0.5*k[0][5] );
	k[1][1] = h*du2dt( t+0.5*h, u1+0.5*k[0][0], u2+0.5*k[0][1], u3+0.5*k[0][2], v1+0.5*k[0][3], v2+0.5*k[0][4], v3+0.5*k[0][5] );
	k[1][2] = h*du3dt( t+0.5*h, u1+0.5*k[0][0], u2+0.5*k[0][1], u3+0.5*k[0][2], v1+0.5*k[0][3], v2+0.5*k[0][4], v3+0.5*k[0][5] );
	k[1][3] = h*dv1dt( t+0.5*h, u1+0.5*k[0][0], u2+0.5*k[0][1], u3+0.5*k[0][2], v1+0.5*k[0][3], v2+0.5*k[0][4], v3+0.5*k[0][5], w );
	k[1][4] = h*dv2dt( t+0.5*h, u1+0.5*k[0][0], u2+0.5*k[0][1], u3+0.5*k[0][2], v1+0.5*k[0][3], v2+0.5*k[0][4], v3+0.5*k[0][5] );
	k[1][5] = h*dv3dt( t+0.5*h, u1+0.5*k[0][0], u2+0.5*k[0][1], u3+0.5*k[0][2], v1+0.5*k[0][3], v2+0.5*k[0][4], v3+0.5*k[0][5] );

	k[2][0] = h*du1dt( t+0.5*h, u1+0.5*k[1][0], u2+0.5*k[1][1], u3+0.5*k[1][2], v1+0.5*k[1][3], v2+0.5*k[1][4], v3+0.5*k[1][5] );
	k[2][1] = h*du2dt( t+0.5*h, u1+0.5*k[1][0], u2+0.5*k[1][1], u3+0.5*k[1][2], v1+0.5*k[1][3], v2+0.5*k[1][4], v3+0.5*k[1][5] );
	k[2][2] = h*du3dt( t+0.5*h, u1+0.5*k[1][0], u2+0.5*k[1][1], u3+0.5*k[1][2], v1+0.5*k[1][3], v2+0.5*k[1][4], v3+0.5*k[1][5] );
	k[2][3] = h*dv1dt( t+0.5*h, u1+0.5*k[1][0], u2+0.5*k[1][1], u3+0.5*k[1][2], v1+0.5*k[1][3], v2+0.5*k[1][4], v3+0.5*k[1][5], w );
	k[2][4] = h*dv2dt( t+0.5*h, u1+0.5*k[1][0], u2+0.5*k[1][1], u3+0.5*k[1][2], v1+0.5*k[1][3], v2+0.5*k[1][4], v3+0.5*k[1][5] );
	k[2][5] = h*dv3dt( t+0.5*h, u1+0.5*k[1][0], u2+0.5*k[1][1], u3+0.5*k[1][2], v1+0.5*k[1][3], v2+0.5*k[1][4], v3+0.5*k[1][5] );

	k[3][0] = h*du1dt( t+h, u1+k[2][0], u2+k[2][1], u3+k[2][2], v1+k[2][3], v2+k[2][4], v3+k[2][5] );
	k[3][1] = h*du2dt( t+h, u1+k[2][0], u2+k[2][1], u3+k[2][2], v1+k[2][3], v2+k[2][4], v3+k[2][5] );
	k[3][2] = h*du3dt( t+h, u1+k[2][0], u2+k[2][1], u3+k[2][2], v1+k[2][3], v2+k[2][4], v3+k[2][5] );
	k[3][3] = h*dv1dt( t+h, u1+k[2][0], u2+k[2][1], u3+k[2][2], v1+k[2][3], v2+k[2][4], v3+k[2][5], w );
	k[3][4] = h*dv2dt( t+h, u1+k[2][0], u2+k[2][1], u3+k[2][2], v1+k[2][3], v2+k[2][4], v3+k[2][5] );
	k[3][5] = h*dv3dt( t+h, u1+k[2][0], u2+k[2][1], u3+k[2][2], v1+k[2][3], v2+k[2][4], v3+k[2][5] );

	u1 += ( k[0][0] + 2*(k[1][0] + k[2][0]) + k[3][0] )/6.0;
	u2 += ( k[0][1] + 2*(k[1][1] + k[2][1]) + k[3][1] )/6.0;
	u3 += ( k[0][2] + 2*(k[1][2] + k[2][2]) + k[3][2] )/6.0;
	v1 += ( k[0][3] + 2*(k[1][3] + k[2][3]) + k[3][3] )/6.0;
	v2 += ( k[0][4] + 2*(k[1][4] + k[2][4]) + k[3][4] )/6.0;
	v3 += ( k[0][5] + 2*(k[1][5] + k[2][5]) + k[3][5] )/6.0;
}
