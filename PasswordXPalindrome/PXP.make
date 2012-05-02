


PXP.out : PasswordXPalindrome.o main.o
	g++ -o PXP.out PasswordXPalindrome.o main.o

PasswordXPalindrome.o : PasswordXPalindrome.cpp PasswordXPalindrome.h
	g++ -c PasswordXPalindrome.cpp

main.o : main.cpp PasswordXPalindrome.h
	g++ -c main.cpp

clean:
	rm *.o *.out
