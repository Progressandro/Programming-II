CC = g++ -std=c++11

Node:
	$(CC) -c Node.hpp

List:
	$(CC) -c List.hpp

ListTest: Node List ListTest.cpp
	$(CC) -g ListTest.cpp -o ListTest
	./ListTest

clean:
	rm -rf *.gch *~
