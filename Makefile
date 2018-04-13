CFLAGS=-std=c++11 -g

all: v1 v2 v3 vm

v1: v1.cpp
	g++ $(CFLAGS) v1.cpp -o v1
	
v2: v2.cpp
	g++ $(CFLAGS) v2.cpp -o v2
	
v3: v3.cpp
	g++ $(CFLAGS) v3.cpp -o v3
	
vm: vectormapdriver.cpp VectorMap.h
	g++ $(CFLAGS) vectormapdriver.cpp -o vm