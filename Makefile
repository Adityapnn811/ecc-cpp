FILE=*.cpp
compile:
	g++ main.cpp -I ./ math/${FILE} point/${FILE} ecc/${FILE} -o main

run:
	./main

clean:
	rm main

all: compile run