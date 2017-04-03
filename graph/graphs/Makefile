#
# Makefile for Graph Traversal Lab
#
CXX = g++
FLAGS = -std=c++11 -g -Wall

graphTraversal: main.cpp graph.cpp graph.h
	${CXX} ${FLAGS} -o graphTraversal graph.cpp main.cpp

clean:
	rm -f graphTraversal
	
provide:
	provide comp15 lab10 main.cpp graph.cpp graph.h Makefile
