#Para la solucion de este ejercicio, me base en los codigos de los siguientes links
#https://github.com/matplotlib/matplotlib/issues/8360
#https://github.com/matplotlib/matplotlib/issues/8528
#http://rhgftk.blogspot.com/2019/04/matplotlib-animationfuncanimation.html

import matplotlib.pyplot as plt
import matplotlib.animation as animation
import numpy as np

#Se cargan los datos y se multiplican por 100 para que sean visibles en la animacion. 
data = np.loadtxt("1grafica.dat")
t = data[:,0]
u1 = 100*data[:,1]
u2 = 100*data[:,2]
u3 = 100*data[:,3]


def evolve(i):
	#Para cada uno de los pisos, se crea un linspace con las posiciones en x de la vibracion
	xfloor1 = np.linspace( a-u1[i], b-u1[i], 10 )
	xfloor2 = np.linspace( a-u2[i], b-u2[i], 10 )
	xfloor3 = np.linspace( a-u3[i], b-u3[i], 10 )

	#Se actualizan los datos con los valores anteriormente creados 
	f1.set_xdata( xfloor1 )
	f2.set_xdata( xfloor2 )
	f3.set_xdata( xfloor3 )
	
	#los datos de j, k y l indican la posicion de paredes de los pisos del edificio para ser actualizada
	j1.set_data( [1,xfloor1[0]], [0,1] )
	j2.set_data( [2,xfloor1[-1]], [0,1] )

	k1.set_data( [xfloor1[0], xfloor2[0]], [1,2] )
	k2.set_data( [xfloor1[-1], xfloor2[-1]], [1,2] )

	l1.set_data( [xfloor2[0], xfloor3[0]], [2,3] )
	l2.set_data( [xfloor2[-1], xfloor3[-1]], [2,3] )

	#Se crea el siguiente comando para crear la animacion, se saco de los links que se especificaron al comienzo del ejercicio 
if __name__ == "__main__":
	a,b = 1,2
	x = np.linspace( a, b, 10 )

	fig = plt.figure( figsize = (5,5) )
	plt.axis([ 0.5, 2.5, 0, 3.5 ])
	
	#Se grafica desde el suelo hasta el tercer piso
	plt.plot( x, len(x)*[0], "k", lw =2 )
	f1, = plt.plot( x, len(x)*[1], "k", lw=2 )
	f2, = plt.plot( x, len(x)*[2], "k", lw=2 )
	f3, = plt.plot( x, len(x)*[3], "k", lw=2 )
	
	#Con los valores de j, k y l, se grafican las paredes del primer, segundo y tercer piso 
	j1,= plt.plot( [1,1], [0,1], "-ok", lw=2 )
	j2,= plt.plot( [2,2], [0,1], "-ok", lw=2 )
	
	k1,= plt.plot( [1,1], [1,2], "-ok", lw=2 )
	k2,= plt.plot( [2,2], [1,2], "-ok", lw=2 )

	l1,= plt.plot( [1,1], [2,3], "-ok", lw=2 )
	l2,= plt.plot( [2,2], [2,3], "-ok", lw=2 )
	
	#Se especifica el tiempo la animacion
	T = np.arange( 0, len(u1), 1 )
	#Se llama la funcion para crear la animacion 
	a1 = animation.FuncAnimation( fig, evolve, T, interval=25 )
	plt.show()
