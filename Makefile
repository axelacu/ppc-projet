
all: tested

tested: install
	cd bin; \
	LD_LIBRARY_PATH=./lib; \
	./main; \
	./composant1; \
	./composant2; \
	./composant3; \
	./composant4; \
	./bloc;
	#./main Composant1 3 4; \
	#./main Composant2 3 4;

install:
	cd main && ${MAKE} install

clean:
	cd main && ${MAKE} clean
