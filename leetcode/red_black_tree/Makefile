#
# Makefile for Red-black Tree
#
CXX = g++ -std=c++11
FLAGS =  -g -Wall 

bst: RedBlackTree.cpp RedBlackTree.h main.cpp pretty_print.cpp
	${CXX} ${FLAGS} -o redblacktree RedBlackTree.cpp \
		main.cpp pretty_print.cpp
clean:
	rm -f redblacktree

provide:
	provide comp15 redblacktree main.cpp RedBlackTree.cpp RedBlackTree.h \
	        pretty_print.cpp ReadMe.md Makefile

