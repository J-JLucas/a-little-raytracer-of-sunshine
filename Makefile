

buildTests: src/tuple.cpp  test/testtuple.cpp 
	clang++	-std=c++17 -Wall -o runTests src/tuple.cpp test/testtuple.cpp

buildProjectile: test/projectile.cpp src/tuple.cpp
	clang++ -std=c++17 -Wall -o Projectile test/projectile.cpp src/tuple.cpp
