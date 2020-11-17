
#All Targets
all: bin/cTrace

bin/cTrace: bin/main.o bin/Session.o bin/Graph.o bin/Agent.o bin/Virus.o bin/ContactTracer.o  bin/Tree.o bin/CycleTree.o bin/MaxRankTree.o bin/RootTree.o
		@echo 'building target: bin/cTrace'
		@echo 'Invoking: C++ Linker'
		g++ -o bin/cTrace bin/main.o bin/Session.o bin/Graph.o bin/Agent.o bin/Virus.o bin/ContactTracer.o  bin/Tree.o bin/CycleTree.o bin/MaxRankTree.o bin/RootTree.o
		@echo 'Finished Building Target: bin/cTrace'

#Depends on the source and header files
bin/main.o: src/main.cpp
		g++ -g -Wall -Weffc++ -std=c++11 -c -Iinclude -o bin/main.o src/main.cpp

#Depends on the source and header files
bin/Session.o: src/Session.cpp
		g++ -g -Wall -Weffc++ -std=c++11 -c -Iinclude -o bin/Session.o src/Session.cpp

#Depends on the source and header files
bin/Virus.o: src/Virus.cpp
		g++ -g -Wall -Weffc++ -std=c++11 -c -Iinclude -o bin/Virus.o src/Virus.cpp

#Depends on the source and header files
bin/ContactTracer.o: src/ContactTracer.cpp
		g++ -g -Wall -Weffc++ -std=c++11 -c -Iinclude -o bin/ContactTracer.o src/ContactTracer.cpp

#Depends on the source and header files
bin/MaxRankTree.o: src/MaxRankTree.cpp
		g++ -g -Wall -Weffc++ -std=c++11 -c -Iinclude -o bin/MaxRankTree.o src/MaxRankTree.cpp

#Depends on the source and header files
bin/CycleTree.o: src/CycleTree.cpp
		g++ -g -Wall -Weffc++ -std=c++11 -c -Iinclude -o bin/CycleTree.o src/CycleTree.cpp

#Depends on the source and header files
bin/RootTree.o: src/RootTree.cpp
		g++ -g -Wall -Weffc++ -std=c++11 -c -Iinclude -o bin/RootTree.o src/RootTree.cpp

#Depends on the source and header files
bin/Graph.o: src/Graph.cpp
		g++ -g -Wall -Weffc++ -std=c++11 -c -Iinclude -o bin/Graph.o src/Graph.cpp

#Depends on the source and header files
bin/Agent.o: src/Agent.cpp
		g++ -g -Wall -Weffc++ -std=c++11 -c -Iinclude -o bin/Agent.o src/Agent.cpp

#Depends on the source and header files
bin/Tree.o: src/Tree.cpp
		g++ -g -Wall -Weffc++ -std=c++11 -c -Iinclude -o bin/Tree.o src/Tree.cpp



clean:
		rm -f bin/*
