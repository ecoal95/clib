#!/bin/sh
echo "" >> build/clib/clib.h
for file in `ls src/common/*.h`; do
	file=${file#src/}
	echo "#include \"$file\"" >> build/clib/clib.h
done

