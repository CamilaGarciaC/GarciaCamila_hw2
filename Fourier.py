import numpy as np
import matplotlib.pylab as plt
import scipy as sp
import scipy.io.wavfile as wav
from scipy.fftpack import fft, fftfreq,ifft
from scipy import interpolate

#Se carga y almacena los datos de signalSuma.dat
signalSuma = np.genfromtxt("signalSuma.dat")
x_sum=signalSuma[:,0]
y_sum=signalSuma[:,1]

#Se carga y se almacena los datos de signal.dat
signal = np.genfromtxt("signal.dat")
x_sig=signal[:,0]
y_sig=signal[:,1]

#Graficas con los dos subplots para ambos archivos
plt.figure()
plt.subplot(2,1,1)
plt.plot(x_sig, y_sig )
plt.title("Valores signal.dat")
plt.xlabel("x")
plt.ylabel("y")
plt.subplot(2,1,2)
plt.plot(x_sum, y_sum)
plt.title("Valores de signalSuma.dat")
plt.xlabel("x")
plt.ylabel("y")
plt.savefig("GarciaCamila_SubplotsGraficas.pdf")

#Se hace la definicion de transformada de fourierpara los datos de la señal.
def DFT(x):
    N = len(x)
    n= np.arange(len(x))
    F_k=[]
    for k in range(N):
        omega = 2*np.pi*n*k/N
        F_real = x*np.cos(2*np.pi*n*k/N)
        F_im = x*np.sin(2*np.pi*n*k/N)
        F_r = np.sum(F_real)
        F_i = np.sum(F_im)
        Fk= F_r -1j*F_i
        F_k.append(Fk)
    return F_k


