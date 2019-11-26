grafica100.png : data10.dat data30.dat data100.dat graficar.py FTCS.x
	python graficar.py

data10.dat : FTCS.x
	./FTCS.x 0 > data10.dat
data30.dat : FTCS.x
	./FTCS.x 1 > data30.dat
data100.dat : FTCS.x
	./FTCS.x 2 > data100.dat
	
FTCS.x : FTCS.cpp
	c++ FTCS.cpp -o FTCS.x
	
clean :
	rm -r *.dat *.x *.png