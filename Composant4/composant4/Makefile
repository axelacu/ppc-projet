CPPFLAGS=-I../interfaces

COMPOSANT = composant4

LIBSO = lib${COMPOSANT}.so
LIBSO_OBJS = ${COMPOSANT}.o ../hash/hash.o ../bloc/bloc.o
DESTINATION_DIR = ../lib
DESTINATION_LIBSO = ${DESTINATION_DIR}/${LIBSO}

include ../gcc.mk


all: $(LIBSO)
clean:
	rm -f ${LIBSO} ${DESTINATION_LIBSO} ${LIBSO_OBJS}

install: ${DESTINATION_DIR} ${DESTINATION_LIBSO}


${DESTINATION_LIBSO}: ${LIBSO}
	cp $< $@

${DESTINATION_DIR}:
	mkdir -p $@