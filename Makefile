compile:
	g++ main.cpp bignum/bignum.cc -o main

run:
	./main

clean:
	rm main

all:
	compile run