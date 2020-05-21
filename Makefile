
all: tested

tested: install
	cd bin; \
	LD_LIBRARY_PATH=./lib; \
	./main; \
	./Composant1; \
	./Composant2; \
	./Composant3; \
	./Composant4; \
	./Bloc;
	#./main Composant1 3 4; \
	#./main Composant2 3 4;

install:
	cd main && ${MAKE} install

clean:
	cd main && ${MAKE} clean
