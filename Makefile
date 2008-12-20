SRCS = tikitags.c

tikitags.o: $(SRCS)
	gcc -c tikitags.c -o tikitags.o

static: tikitags.o
	ar rcs libtiki.a tikitags.o

dynamic: tikitags.o
	gcc -shared -Wl,-soname,libtiki.so.1 -o libtiki.so.1.0.1

main: static
	gcc --static main.c -L. -ltiki -lusb -o main

main_dynamic: dynamic
	gcc main.c -o main_dynamic -L. -ltiki -lusb

clean:
	rm *.o *~ *.a *.so* main main_dynamic
