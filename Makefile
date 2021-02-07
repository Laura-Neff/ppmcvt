## Makefile

all: pbm pbm_aux ppmcvt

pbm: pbm.h pbm.c Makefile
	gcc -c -ggdb -std=c99 -Wall -Wformat=0 pbm.c

pbm_aux: pbm.h pbm_aux.c Makefile
	gcc -c -ggdb -std=c99 -Wall -Wformat=0 pbm_aux.c

ppmcvt: pbm.h ppmcvt.c
	gcc -c -ggdb -std=c99 -Wall -Wformat=0 ppmcvt.c
	gcc pbm.o pbm_aux.o ppmcvt.o -o ppmcvt