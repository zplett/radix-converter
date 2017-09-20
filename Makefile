all:frequency encode_bits decode_bits  

frequency: frequency.c
	gccx -g -o frequency frequency.c

encode_bits.o: encode_bits.c bits.h bits.c
	gccx -g -c encode_bits.c bits.c 

encode_bits: encode_bits.o bits.o
	gccx -g encode_bits.o bits.o -o encode_bits -lm

decode_bits.o: decode_bits.c bits.h bits.c 
	gccx -g -c decode_bits.c bits.c 

decode_bits: decode_bits.o bits.o
	gccx -g decode_bits.o bits.o -o decode_bits -lm

clean:
	rm -f frequency encode_bits decode_bits *.o
