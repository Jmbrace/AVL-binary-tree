main: main.o binaryTree.o
	g++ -o main main.o binaryTree.o

main.o: main.cpp binaryTree.h
	g++ -c main.cpp

binaryTree.o: binaryTree.cpp 
	g++ -c binaryTree.cpp

clean:
	rm main binaryTree.o main.o