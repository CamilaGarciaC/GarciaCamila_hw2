#include <iostream>
#include <cmath>
#include <fstream>
#include <vector>

using namespace std;

#define TAB "\t"

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
void rungekutta( double t, double &u1, double &u2, double &u3, double &v1, double &v2, double &v3, double w ){
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

//Se crea funcion que halla los ui(t)max

double maximo( double* arr, int size ){
	int i, j;
	double tmp;

	for( i = 1; i < size; i++ ){
		for( j = 0; j < size-1; j++ ){
			if( arr[j] > arr[j+1] ){
				tmp = arr[j];
				arr[j] = arr[j+1];
				arr[j+1] = tmp;
			}
		}
	}

	return arr[size-1];
}

//Main que crea los archivos de datos a ser graficados 
int main(int argc, char *argv[]){

	//Agregan los datos para la primera grafica de ui(t) en funcion del tiempo
	ofstream data;
	data.open("1grafica.dat");

	double w = sqrt(k/m);
	double u1 = 0.0, u2 = 0.0, u3 = 0.0, v1 = 0.0, v2 = 0.0, v3 = 0.0;

	for( double t = 0.0; t < 200; t += h ){
		rungekutta( t, u1, u2, u3, v1, v2, v3, w );
		data << t << TAB << u1 << TAB << u2 << TAB << u3 << TAB << v1 << TAB << v2 << TAB << v3 << endl;
	}	
	data.close();

	//Agregan los datos para la segunda grafica de ui(t) en funcion del tiempo
	ofstream data1;
	data1.open("2grafica.dat");

	double w2 = 0.8;
	double u11 = 0.0, u22 = 0.0, u33 = 0.0, v11 = 0.0, v22 = 0.0, v33 = 0.0;

	for( double t1 = 0.0; t1 < 200; t1 += h ){
		rungekutta( t1, u11, u22, u33, v11, v22, v33, w2 );
		data1 << t1 << TAB << u11 << TAB << u22 << TAB << u33 << TAB << v11 << TAB << v22 << TAB << v33 << endl;
	}	
	data1.close();

	//Agregan los datos para la tercera grafica de ui(t) en funcion del tiempo

	ofstream data3;
	data3.open("3grafica.dat");

	double w3 = 1.8;
	double u111 = 0.0, u222 = 0.0, u333 = 0.0, v111 = 0.0, v222 = 0.0, v333 = 0.0;

	for( double t2 = 0.0; t2 < 200; t2 += h ){
		rungekutta( t2, u111, u222, u333, v111, v222, v333, w3 );
		data3 << t2 << TAB << u111 << TAB << u222 << TAB << u333 << TAB << v111 << TAB << v222 << TAB << v333 << endl;
	}	
	data3.close();

	//Agregan los datos para la tercera grafica de ui(t) en funcion del tiempo

	ofstream data4;
	data4.open("4grafica.dat");

	double w4 = 2.6;
	double u1111 = 0.0, u2222 = 0.0, u3333 = 0.0, v1111 = 0.0, v2222 = 0.0, v3333 = 0.0;

	for( double t3 = 0.0; t3 < 200; t3 += h ){
		rungekutta( t3, u1111, u2222, u3333, v1111, v2222, v3333, w4 );
		data4 << t3 << TAB << u1111 << TAB << u2222 << TAB << u3333 << TAB << v1111 << TAB << v2222 << TAB << v3333 << endl;
	}	
	data4.close();

	//Se agregan los datos para la grafica de ui(t)max
	ofstream data2;
	data2.open("graficamax.dat");

	double wmin = 0.2*sqrt(k/m);
	double wmax = 3.0*sqrt(k/m);
	double dw = (wmax-wmin)/99.0;
	
	for( double W = wmin; W < wmax; W += dw ){
		double u1 = 0.0, u2 = 0.0, u3 = 0.0, v1 = 0.0, v2 = 0.0, v3 = 0.0;
		vector<double> x1, x2, x3;

		for( double t = 0.0; t < 200; t += h ){
			rungekutta( t, u1, u2, u3, v1, v2, v3, W );
		
			x1.push_back(u1);
			x2.push_back(u2);
			x3.push_back(u3);
		}

		double u1_max = maximo( x1.data(), x1.size() );
		double u2_max = maximo( x2.data(), x2.size() );
		double u3_max = maximo( x3.data(), x3.size() );
		data2 << W << TAB << u1_max << TAB << u2_max << TAB << u3_max << endl;
	}
	data2.close();

	return 0;
}
