
all: tested

tested: install
	cd bin; \
	LD_LIBRARY_PATH=.; \
	./main;

install:
	cd main && ${MAKE} install

clean:
	cd main && ${MAKE} clean
