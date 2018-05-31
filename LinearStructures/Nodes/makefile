CC = g++ -std=c++11
NodeLibs = Node.hpp.gch

Node.gch:
	$(CC) -c Node.hpp

NodeTest: Node.gch NodeTest.cpp
	$(CC) NodeTest.cpp -o NodeTest
	./NodeTest

clean:
	rm -rf *.gch *~
