
#All Targets
all: bin/finish

bin/finish: bin/Session.o
        @echo 'building target: bin/finish '
        @echo 'Invoking: C++ Linker'
		g++ -o bin/main bin/Session.o
		@echo 'Finished Building Target: bin/finish

#Depends on the source and header files
bin/Session.o: Session.cpp bin/Graph.o bin/Virus.o bin/ContactTracer.o
		g++ -g -Wall -Weffc++ -std=c++11 -c -Iinclude -0 bin/Session.o src/Session.cpp

#Depends on the source and header files
bin/Virus.o: Virus.cpp bin/Session.o
		g++ -g -Wall -Weffc++ -std=c++11 -c -Iinclude -0 bin/Virus.o src/Virus.cpp

#Depends on the source and header files
bin/ContactTracer.o: ContactTracer.cpp bin/Session.o
		g++ -g -Wall -Weffc++ -std=c++11 -c -Iinclude -0 bin/ContactTracer.o src/ContactTracer.cpp

#Depends on the source and header files
bin/MaxRankTree.o: MaxRankTree.cpp
		g++ -g -Wall -Weffc++ -std=c++11 -c -Iinclude -0 bin/MaxRankTree.o src/MaxRankTree.cpp

#Depends on the source and header files
bin/CycleTree.o: CycleTree.cpp
		g++ -g -Wall -Weffc++ -std=c++11 -c -Iinclude -0 bin/CycleTree.o src/CycleTree.cpp

#Depends on the source and header files
bin/RootTree.o: RootTree.cpp
		g++ -g -Wall -Weffc++ -std=c++11 -c -Iinclude -0 bin/RootTree.o src/RootTree.cpp

#Depends on the source and header files
bin/Graph.o: Graph.cpp
		g++ -g -Wall -Weffc++ -std=c++11 -c -Iinclude -0 bin/Graph.o src/Graph.cpp

clean:
		rm -f bin/*
