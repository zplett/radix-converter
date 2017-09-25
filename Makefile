OBall:frequency encode_bits decode_bits test tohex tooctal todecimal tobinary  

frequency: frequency.c
	gccx -g -o frequency frequency.c

encode_bits.o: encode_bits.c bits.h bits.c getnum.h getnum.c
	gccx -g -c encode_bits.c bits.c getnum.c

encode_bits: encode_bits.o bits.o getnum.o
	gccx -g encode_bits.o bits.o getnum.o -o encode_bits -lm

decode_bits.o: decode_bits.c bits.h bits.c getnum.h getnum.c 
	gccx -g -c decode_bits.c bits.c getnum.c

decode_bits: decode_bits.o bits.o getnum.o
	gccx -g decode_bits.o bits.o getnum.o -o decode_bits -lm

test: test.o bits.o getnum.o
	gccx -g test.o bits.o getnum.o -o test -lm

test.o: test.c bits.h bits.c getnum.h getnum.c
	gccx -g -c test.c bits.c getnum.c

tohex: tohex.o bits.o getnum.o
	gccx -g tohex.o bits.o getnum.o -o tohex -lm

tohex.o: tohex.c bits.h bits.c getnum.h getnum.c
	gccx -g -c tohex.c bits.c getnum.c

tooctal: tooctal.o bits.o getnum.o
	gccx -g tooctal.o bits.o getnum.o -o tooctal -lm

tooctal.o: tooctal.c bits.h bits.c getnum.h getnum.c
	gccx -g -c tooctal.c bits.c getnum.c

todecimal: todecimal.o bits.o getnum.o
	gccx -g todecimal.o bits.o getnum.o -o todecimal -lm

todecimal.o: todecimal.c bits.h bits.c getnum.h getnum.c
	gccx -g -c todecimal.c bits.c getnum.c

tobinary: tobinary.o bits.o getnum.o
	gccx -g tobinary.o bits.o getnum.o -o tobinary -lm

tobinary.o: tobinary.c bits.h bits.c getnum.h getnum.c
	gccx -g -c tobinary.c bits.c getnum.c 

clean:
	rm -f frequency encode_bits decode_bits test todecimal tobinary tohex tooctal *.o
