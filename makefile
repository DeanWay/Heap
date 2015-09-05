all: libheap.a clean
libheap.a: Heap.o
	ar r libheap.a Heap.o
heap.o: Heap.c Heap.h
	gcc -c Heap.c
clean:
	rm *.o
