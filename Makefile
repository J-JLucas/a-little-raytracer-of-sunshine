

buildTests: src/tuple.cpp  test/testtuple.cpp 
	clang++	-std=c++17 -Wall -o runTests src/tuple.cpp test/testtuple.cpp
