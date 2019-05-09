import numpy as np 
import matplotlib.pylab as plt

datos = np.genfromtxt("1grafica.dat")
w=datos[:,0]
u1_max=datos[:,1]
u2_max=datos[:,2]
u3_max=datos[:,3]

plt.figure()
plt.plot(w, u1_max)
plt.plot(w, u2_max)
plt.plot(w, u3_max)
plt.title("Amplitudes ui(t)max en funcion de w")
plt.xlabel("w")
plt.ylabel("ui(t)max")
plt.savefig("GarciaCamila_Amplitudui(t)maxVsW.pdf")

datos = np.genfromtxt("4graficas.dat")
t=datos[:,0]
u1=datos[:,1]
u2=datos[:,2]
u3=datos[:,3]

plt.figure()
plt.plot(t, u1)
plt.plot(t, u2)
plt.plot(t, u3)
plt.title("Amplitudes ui(t)max en funcion de w")
plt.xlim(0, 50)
plt.xlabel("t")
plt.ylabel("ui(t)")
plt.savefig("GarciaCamila_uitEnFDelT.pdf")

