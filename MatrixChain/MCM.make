

MCM.out : MatrixMultiplier.o main.o
	g++ -o MCM.out MatrixMultiplier.o main.o

MatrixMultiplier.o : MatrixMultiplier.h MatrixMultiplier.cpp
	g++ -c MatrixMultiplier.cpp

main.o: main.cpp MatrixMultiplier.h
	g++ -c main.cpp

clean:
	rm *.o *.out

