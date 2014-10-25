C_FILES := $(wildcard *.c)
H_FILES := $(wildcard *.h)
OBJ_FILES := $(addprefix ../../build/o/common/,$(notdir $(C_FILES:.c=.o)))

all: $(OBJ_FILES)

../../build/o/common/%.o: %.c %.h
	gcc -Wall -c -o $@ $<

clean:
	rm -r ../../build/o/common/*.o

