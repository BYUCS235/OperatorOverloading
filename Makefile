CFLAGS=-std=c++11 -g

vm: vectormapdriver.cpp VectorMap.h
	g++ $(CFLAGS) vectormapdriver.cpp -o vm
	
map: map.cpp 
	g++ $(CFLAGS) map.cpp -o map
