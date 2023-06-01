
output: main.o patron.o book.o loan.o patrons.o books.o loans.o
	g++ main.o patron.o book.o loan.o patrons.o books.o loans.o -o output
	
main.o: main.cpp
	g++ -c main.cpp
	
patron.o: patron.cpp patron.h
	g++ -c patron.cpp
	
book.o: book.cpp book.h
	g++ -c book.cpp
	
loan.o: loan.cpp loan.h
	g++ -c loan.cpp
	
patrons.o: patrons.cpp patrons.h patron.h
	g++ -c patrons.cpp
	
books.o: books.cpp books.h book.h
	g++ -c books.cpp
	
loans.o: loans.cpp loans.h loan.h
	g++ -c loans.cpp
	
clean:
	rm *.o output