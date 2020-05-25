CPPFLAGS=-I /usr/include/python3.6m

COMPOSANT = Composant6
LIBS=-lpython3.6m -lboost_python3-py36

LIBSO = lib${COMPOSANT}.so
LIBSO_OBJS = signature.o
DESTINATION_DIR = ../lib
DESTINATION_LIBSO = ${DESTINATION_DIR}/${LIBSO}
LDFLAGS = -lboost_python -lboost_system -lpython3.6m

include ../gcc.mk


all: ${DESTINATION_LIBSO}
clean:
	rm -f ${LIBSO} ${DESTINATION_LIBSO} ${LIBSO_OBJS}

install: ${DESTINATION_DIR} ${DESTINATION_LIBSO}


${DESTINATION_LIBSO}: ${LIBSO}
	cp -f $< $@

${DESTINATION_DIR}:
	mkdir -p $@
