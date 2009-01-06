SRCS = tikitags.c
CROSS_PYTHON_PATH = /home/kimyh/nfs_qwerk/python/include/python2.4
INCLUDE_USB = /home/kimyh/temp/tikitag/trunk/pytiki/include
LIBPATH = /home/kimyh/temp/tikitag/trunk/pytiki/lib
main:
	swig -python tikitags.i
	gcc -c tikitags.c tikitags_wrap.c -I/usr/include/python2.5/
	ld -shared tikitags.o tikitags_wrap.o -o _pytiki.so -lusb
cross:
	swig -python tikitags.i
	arm-linux-gcc -c tikitags.c tikitags_wrap.c -I$(CROSS_PYTHON_PATH) -I$(INCLUDE_USB)
	arm-linux-ld -shared tikitags.o tikitags_wrap.o -o _pytiki.so -lusb -L$(LIBPATH)
clean:
	rm -f *.o *.so* *.py*
