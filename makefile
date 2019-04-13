BASE = BinSearchTree

all:binTree.x  BinSearchTree.o main.o
CFlag = -g -std=c++11
binTree.x: $(BASE).o main.o
	g++ $(CFlag) -o binTree.x BinSearchTree.o main.o

BinSearchTree.o: BinSearchTree.cpp BinSearchTree.hpp TreeNode.hpp 
	g++ $(CFlag) -c -o BinSearchTree.o BinSearchTree.cpp

main.o: main.cpp BinSearchTree.hpp TreeNode.hpp
	g++ $(CFlag) -c -o main.o main.cpp
 

clean:
	rm -f *.o *.x *~

