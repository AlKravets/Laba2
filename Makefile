hello: Source.o Class.o
	g++ -o edit Source.o Class.o
Source.o: Source.cpp Class.h
	g++ -c Source.cpp
Class.o: Class.cpp Class.h
	g++ -c Class.cpp