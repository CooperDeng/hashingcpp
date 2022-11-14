all: openhttest orderedhttest

openhttest: openhttest.cpp
	g++ openhttest.cpp Node.cpp hashopen.cpp -o openhttest

orderedhttest: orderedhttest.cpp
	g++ orderedhttest.cpp Node.cpp linkedlist.cpp hashchain.cpp -o orderedhttest