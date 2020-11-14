
#All Targets
all: main

main: bin/Session.o
        @echo 'building target: main'
        @echo 'Invoking: C++ Linker'
        g++ -o bin/main bin/Session.o
        @echo 'Finished Building Target: main'

#Depends on the source and header files
bin/Session.o: src/Session.cpp src/Virus.cpp
        g++ -g -Wall -Weffc++ -std=c++11 -c -Iinclude -0 bin/Session.o src/Session.cpp

#Depends on the source and header files
bin/Virus.o: src/Virus.cpp
        g++ -g -Wall -Weffc++ -std=c++11 -c -Iinclude -0 bin/Virus.o src/Virus.cpp

#Depends on the source and header files
bin/ContactTracer.o: src/ContactTracer.cpp
        g++ -g -Wall -Weffc++ -std=c++11 -c -Iinclude -0 bin/ContactTracer.o src/ContactTracer.cpp

#Depends on the source and header files
bin/MaxRankTree.o: src/MaxRankTree.cpp
        g++ -g -Wall -Weffc++ -std=c++11 -c -Iinclude -0 bin/MaxRankTree.o src/MaxRankTree.cpp

#Depends on the source and header files
bin/CycleTree.o: src/CycleTree.cpp
        g++ -g -Wall -Weffc++ -std=c++11 -c -Iinclude -0 bin/CycleTree.o src/CycleTree.cpp

#Depends on the source and header files
bin/RootTree.o: src/RootTree.cpp
        g++ -g -Wall -Weffc++ -std=c++11 -c -Iinclude -0 bin/RootTree.o src/RootTree.cpp

#Depends on the source and header files
bin/Graph.o: src/Graph.cpp
        g++ -g -Wall -Weffc++ -std=c++11 -c -Iinclude -0 bin/Graph.o src/Graph.cpp

clean:
        rm -f bin/*
