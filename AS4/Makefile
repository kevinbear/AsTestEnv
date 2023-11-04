headertest: clean 
	g++ -std=c++11 -Iinclude src/unittest.cpp -o headertest

unittest: clean vector.o
	g++ -std=c++11 -Iinclude src/unittest.cpp vector.o -o unittest

vector.o:
	g++ -std=c++11 -Iinclude -c src/Vector.cpp -o vector.o

clean:
	rm -rf unittest vector.o
