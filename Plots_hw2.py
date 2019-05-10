import numpy as np 
import matplotlib.pylab as plt

#Se importan los datos para la grafica de amplitud maxima en funcion de w. 
datos = np.genfromtxt("graficamax.dat")
w=datos[:,0]
u1_max=datos[:,1]
u2_max=datos[:,2]
u3_max=datos[:,3]

#Se grafica la amplitud maxima en funcion de w. 
plt.figure()
plt.plot(w, u1_max)
plt.plot(w, u2_max)
plt.plot(w, u3_max)
plt.title("Amplitudes ui(t)max en funcion de w")
plt.xlabel("t")
plt.ylabel("ui(t)max")
plt.savefig("GarciaCamila_Amplitudui(t)maxVsW.pdf")

#Se importan los datos para la primera grafica de ui(t)max en funcion de t.
datos = np.genfromtxt("1grafica.dat")
t=datos[:,0]
u1=datos[:,1]
u2=datos[:,2]
u3=datos[:,3]

#Se hace la primera grafica de ui(t)max en funcion de t
plt.figure()
plt.plot(t, u1)
plt.plot(t, u2)
plt.plot(t, u3)
plt.title("Amplitudes ui(t)max en funcion de w")
plt.xlim(0, 50)
plt.xlabel("t")
plt.ylabel("ui(t)")
plt.savefig("PrimeraGraficaUi(t).pdf")

#Se importan los datos para la segunda grafica de ui(t)max en funcion de t.
datos = np.genfromtxt("2grafica.dat")
t=datos[:,0]
u1=datos[:,1]
u2=datos[:,2]
u3=datos[:,3]

#Se hace la segunda grafica de ui(t)max en funcion de t
plt.figure()
plt.plot(t, u1)
plt.plot(t, u2)
plt.plot(t, u3)
plt.title("Amplitudes ui(t)max en funcion de w")
plt.xlim(0, 50)
plt.xlabel("t")
plt.ylabel("ui(t)")
plt.savefig("SegundaGraficaUi(t).pdf")

#Se importan los datos para la tercera grafica de ui(t)max en funcion de t.
datos = np.genfromtxt("3grafica.dat")
t=datos[:,0]
u1=datos[:,1]
u2=datos[:,2]
u3=datos[:,3]

#Se hace la tercera grafica de ui(t)max en funcion de t
plt.figure()
plt.plot(t, u1)
plt.plot(t, u2)
plt.plot(t, u3)
plt.title("Amplitudes ui(t)max en funcion de w")
plt.xlim(0, 50)
plt.xlabel("t")
plt.ylabel("ui(t)")
plt.savefig("TerceraGraficaUi(t).pdf")

#Se importan los datos para la cuarta grafica de ui(t)max en funcion de t.
datos = np.genfromtxt("4grafica.dat")
t=datos[:,0]
u1=datos[:,1]
u2=datos[:,2]
u3=datos[:,3]

#Se hace la cuarta grafica de ui(t)max en funcion de t
plt.figure()
plt.plot(t, u1)
plt.plot(t, u2)
plt.plot(t, u3)
plt.title("Amplitudes ui(t)max en funcion de w")
plt.xlim(0, 50)
plt.xlabel("t")
plt.ylabel("ui(t)")
plt.savefig("CuartaGraficaUi(t).pdf")
