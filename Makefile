Tests: src/Tuple.cpp src/Canvas.cpp test/testTuple.cpp test/testCanvas.cpp test/testSuite.cpp
	clang++ -std=c++17 -Wall -o runTests src/Tuple.cpp src/Canvas.cpp test/testTuple.cpp test/testCanvas.cpp test/testSuite.cpp

Projectile: test/projectile.cpp src/Tuple.cpp
	clang++ -std=c++17 -Wall -o Projectile test/projectile.cpp src/Tuple.cpp src/Canvas.cpp
