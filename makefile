all: generate solve transform

generate: generate.o sudoku.o
	g++ -o generate generate.o sudoku.o

solve: solve.o sudoku.o
	g++ -o solve solve.o sudoku.o

transform: transform.o sudoku.o
	g++ -o transform transform.o sudoku.o

sudoku.o: sudoku.cpp  sudoku.h
	g++ -c sudoku.cpp

generate.o: generate.cpp  sudoku.h
	g++ -c generate.cpp

solve.o: solve.cpp  sudoku.h
	g++ -c solve.cpp

transform.o: transform.cpp sudoku.h
	g++ -c transform.cpp

clean:
	rm generate.o solve.o transform.o sudoku.o
