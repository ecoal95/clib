lib: common
	ar -cvq build/libclib.a $(wildcard build/o/**/*.o)
	cp src/*.h build/clib
	cp src/common/*.h build/clib/common
	ls src/common/*.h
	./generateclib.sh

common:
	cd src/common && $(MAKE)

clean:
	rm build/libclib.a build/clib/*.h build/clib/**/*.h
	cd src/common && $(MAKE) clean
