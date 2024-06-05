compile:
	g++ main.cpp -I ./ math/math.cpp point/Point.cpp -o main

run:
	./main

clean:
	rm main

all: compile run