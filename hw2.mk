Resultados_hw2.pdf : Resultados_hw2.tex GarciaCamila_SubplotsGraficas.pdf  GarciaCamila_Amplitudui(t)maxVsW.pdf  
	pdflatex Resultados_hw2.tex

GarciaCamila_SubplotsGraficas.pdf: Fourier.py
	python Fourier.py

GarciaCamila_Amplitudui(t)maxVsW.pdf: Plots_hw2.py graficamax.dat
	python Plots_hw2.py

graficamax.dat : a.out
	./a.out

a.out : Edificio.cpp
	g++ Edificio.cpp




