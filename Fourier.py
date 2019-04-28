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

#Se declara la función de las frecuencias utilizando el paquete fftfreq
n_sig=len(x_sig)
dx_sig=x_sig[1]-x_sig[0]
f_sig=fftfreq(n_sig, dx_sig)

n_sum=len(x_sum)
dx_sum=x_sum[1]-x_sum[0]
f_sum=fftfreq(n_sum, dx_sum)
print("Se uso el paquete de fftfreq para la grafica de transformada")

#Se grafica la transformada de Fourier y se guarda
fourier_sig=DFT(y_sig)
fourier_sum=DFT(y_sum)

#Se grafica la transformada para ambas señales
plt.figure()
plt.subplot(2,1,1)
plt.plot(f_sig, np.abs(fourier_sig))
plt.title("Transformada de Fourier de signal")
plt.xlabel("Frecuencia")
plt.ylabel("Transoformada de Fourier")
plt.xlim(-650,650)
plt.subplot(2,1,2)
plt.plot(f_sum, np.abs(fourier_sum))
plt.title("Transformada de Fourier de la suma")
plt.xlabel("Frecuencia")
plt.ylabel("Transformada de Fourier")
plt.xlim(-650,650)
plt.savefig("GarciaCamila_Transformadas.pdf")

#Se hace el espectograma de ambas señales-
plt.figure()
plt.subplot(2,1,1)
plt.specgram(y_sig,  NFFT=256, Fs=2, Fc=0)
plt.title("Espectograma de signal")
plt.xlabel("Frecuencia")
plt.ylabel("Transformada de Fourier")
plt.subplot(2,1,2)
plt.specgram(f_sum,  NFFT=256, Fs=2, Fc=0)
plt.title("Espectograma de la suma")
plt.xlabel("Frecuencia")
plt.ylabel("Transformada de Fourier")
plt.savefig("GarciaCamila_Espectogramas.pdf")

#Se almacenan los datos de temblo.txt
'''
temblor = np.genfromtxt("temblor.txt", skip_header=4)
x_tem=temblor[:,0]
y_tem=np.linspace(0, 10000, 10)

plt.figure()
plt.plot(x_tem, y_tem)
plt.title("Espectograma de signal")
plt.xlabel("Frecuencia")
plt.ylabel("Transformada de Fourier")
plt.savefig("GarciaCamila_Temblor.pdf")
'''
