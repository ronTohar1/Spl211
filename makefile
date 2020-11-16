
#All Targets
all: finishedFile

finishedFile: bin/main.o
		@echo 'building target: bin/finishedFile'
		@echo 'Invoking: C++ Linker'
		g++ -o bin/finishedFile bin/main.o
		@echo 'Finished Building Target: bin/finishedFile'

#Depends on the source and header files
bin/main.o: src/main.cpp bin/Session.o
		g++ -g -Wall -Weffc++ -std=c++11 -c -Iinclude -o bin/main.o src/main.cpp bin/Session.o

#Depends on the source and header files
bin/Session.o: src/Session.cpp
		g++ -g -Wall -Weffc++ -std=c++11 -c -Iinclude -o bin/Session.o src/Session.cpp

#Depends on the source and header files
bin/Virus.o: src/Virus.cpp
		g++ -g -Wall -Weffc++ -std=c++11 -c -Iinclude -o bin/Virus.o src/Virus.cpp

#Depends on the source and header files
bin/ContactTracer.o: src/ContactTracer.cpp bin/Agent.o
		g++ -g -Wall -Weffc++ -std=c++11 -c -Iinclude -o bin/ContactTracer.o src/ContactTracer.cpp bin/Agent.o

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
bin/Tree.o: src/Tree.cpp bin/Graph.o bin/Session.o
		g++ -g -Wall -Weffc++ -std=c++11 -c -Iinclude -o bin/Tree.o src/Tree.cpp bin/Graph.o bin/Session.o



clean:
		rm -f bin/*
