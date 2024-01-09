all: docs basic.o area.o volume.o vector.o list.o pi.o llist.o llist-extra.o randomnum.o main.o
	gcc -shared basic.o area.o volume.o vector.o list.o pi.o llist.o llist-extra.o randomnum.o -o libmaff.so
	gcc main.o libmaff.so -o maff

docs: doxconfig
	doxygen doxconfig

basic.o: basic.c
	gcc -fpic -c basic.c

area.o: area.c
	gcc -fpic -c area.c

volume.o: volume.c
	gcc -fpic -c volume.c

vector.o: vector.c
	gcc -fpic -c vector.c

list.o: list.c
	gcc -fpic -c list.c

llist-extra.o: llist-extra.c
	gcc -fpic -c llist-extra.c

main.o: main.c
	gcc -c main.c

pi.o: pi.c
	gcc -fpic -c pi.c

llist.o: llist.c
	gcc -fpic -c llist.c

randomnum.o: randomnum.c
	gcc -fpic -c randomnum.c

clean:
	rm *.o maff libmaff.so
	rm -rf html/ latex/

install:
	cp libmaff.so /usr/lib
	cp maff.h /usr/include
