
#All Targets
all: bin/finish

bin/finish: bin/Session.o
		@echo 'building target: bin/finish'
		@echo 'Invoking: C++ Linker'
		g++ -o bin/main bin/Session.o'
		@echo 'Finished Building Target: bin/finish'

#Depends on the source and header files
bin/Session.o: Session.cpp bin/Graph.o bin/Virus.o bin/ContactTracer.o
		g++ -g -Wall -Weffc++ -std=c++11 -c -Iinclude -o bin/Session.o Session.cpp bin/Graph.o bin/Virus.o bin/ContactTracer.o

#Depends on the source and header files
bin/Virus.o: Virus.cpp Session.h
		g++ -g -Wall -Weffc++ -std=c++11 -c -Iinclude -o bin/Virus.o Virus.cpp Session.h

#Depends on the source and header files
bin/ContactTracer.o: ContactTracer.cpp Session.h Tree.cpp
		g++ -g -Wall -Weffc++ -std=c++11 -c -Iinclude bin/ContactTracer.o ContactTracer.cpp Session.h Tree.cpp

#Depends on the source and header files
bin/MaxRankTree.o: MaxRankTree.cpp
		g++ -g -Wall -Weffc++ -std=c++11 -c -Iinclude -o bin/MaxRankTree.o MaxRankTree.cpp

#Depends on the source and header files
bin/CycleTree.o: CycleTree.cpp
		g++ -g -Wall -Weffc++ -std=c++11 -c -Iinclude -o bin/CycleTree.o CycleTree.cpp

#Depends on the source and header files
bin/RootTree.o: RootTree.cpp
		g++ -g -Wall -Weffc++ -std=c++11 -c -Iinclude -o bin/RootTree.o RootTree.cpp

#Depends on the source and header files
bin/Graph.o: Graph.cpp
		g++ -g -Wall -Weffc++ -std=c++11 -c -Iinclude -o bin/Graph.o Graph.cpp

clean:
		rm -f bin/*
