COMMON_O_FILES := $(wildcard build/o/common/*.o)

lib: common
	ar cr build/libclib.a $(COMMON_O_FILES)

common:
	cd src/common && $(MAKE)

clean:
	rm build/libclib.a
	cd src/common && $(MAKE) clean
