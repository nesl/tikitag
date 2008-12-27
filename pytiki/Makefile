SRCS = tikitags.c

main:
	swig -python tikitags.i
	gcc -c tikitags.c tikitags_wrap.c -I/usr/include/python2.5/
	ld -shared tikitags.o tikitags_wrap.o -o _pytiki.so -lusb

clean:
	rm *.o *.so* *.py*
