
all: tested

tested: install
	cd bin; \
	LD_LIBRARY_PATH=./lib; \
	./main;

install:
	cd main && ${MAKE} install

clean:
	cd main && ${MAKE} clean
