[1mdiff --git a/MaxRankTree.cpp b/MaxRankTree.cpp[m
[1mindex 88a9c1e..866840e 100644[m
[1m--- a/MaxRankTree.cpp[m
[1m+++ b/MaxRankTree.cpp[m
[36m@@ -16,50 +16,44 @@[m [mint MaxRankTree::traceTree() {[m
 [m
 [m
 [m
[31m-vector<int>* MaxRankTree::getMaxRankNode() {[m
[32m+[m[32mint MaxRankTree::getMaxRankNode() {[m
[32m+[m[32m    vector<int> &ranks=getRanks();[m
     vector<Tree*> children=this->getChildren();[m
[31m-    vector<int> *highestRankNode = new vector<int>();[m
[31m-    highestRankNode->push_back(this->getRank());[m
[31m-    highestRankNode->push_back(this->getRoot());[m
[32m+[m[32m    int highestRankNode=children[0]->getRoot();[m
 [m
     if(this->getRank()==0)[m
         return highestRankNode;[m
 [m
[31m-    vector<int>* highestRankChild=this->getMaxRankChild();[m
[31m-    if((*highestRankChild)[0]>(*highestRankNode)[0])[m
[32m+[m[32m    int highestRankChild=this->getMaxRankChild();[m
[32m+[m[32m    if(ranks[highestRankChild]>ranks[highestRankNode])[m
         return highestRankChild;[m
 [m
     return highestRankNode;[m
 }[m
 [m
[31m-std::vector<int>* MaxRankTree::getMaxRankChild() {[m
[31m-[m
[32m+[m[32mint MaxRankTree::getMaxRankChild() {[m
[32m+[m[32m    vector<int> &ranks=getRanks();[m
     vector<Tree*> children=this->getChildren();[m
     int highestRankChild=(children[0])->traceTree();[m
 [m
[31m-    vector<int>* highestRankNode=new vector<int>();[m
[31m-    highestRankNode->push_back(ranks.at(highestRankChild));[m
[31m-    highestRankNode->push_back(highestRankChild);[m
[32m+[m[32m    int highestRankNode=highestRankChild;[m
 [m
     for (int i = 1; i < children.size(); ++i) {[m
 [m
[31m-        vector<int>* currHighestRank=new vector<int>();[m
[31m-        int childHighestRank=(children[i])->traceTree();[m
[31m-        currHighestRank->push_back(ranks.at(childHighestRank));[m
[31m-        currHighestRank->push_back(childHighestRank);[m
[32m+[m[32m        int currHighestRank=children[i]->getRoot();[m
[32m+[m
[32m+[m[32m        if(ranks[currHighestRank]>ranks[highestRankNode])[m
[32m+[m[32m            highestRankNode = currHighestRank;[m
 [m
[31m-        if((*currHighestRank)[0]>(*highestRankNode)[0])[m
[31m-            highestRankNode=currHighestRank;[m
     }[m
 [m
     return highestRankNode;[m
 }[m
 [m
 int MaxRankTree::maxRankTreeTrace() {[m
[31m-    vector<int>* x= getMaxRankNode();[m
[31m-    int nodeIndex=(*x)[1];[m
[31m-    delete x;[m
[32m+[m[32m    int nodeIndex=getMaxRankNode();[m
     return nodeIndex;[m
 }[m
 [m
 [m
[41m+[m
[1mdiff --git a/Tree.cpp b/Tree.cpp[m
[1mindex 58245a9..f62deeb 100644[m
[1m--- a/Tree.cpp[m
[1m+++ b/Tree.cpp[m
[36m@@ -15,7 +15,7 @@[m [mTree* Tree::createTree(const Session &session, int rootLabel) {[m
     //Using bfs algorithm to create a tree[m
     const Graph &g = session.getGraph();[m
     TreeType type = session.getTreeType();//Need to initialize children somehow...? or no need ?[m
[31m-    Tree *myTree = &(getNewTree(type, rootLabel));[m
[32m+[m[32m    Tree *myTree = &(getNewTree(session, rootLabel));[m
     int numOfNodes = g.getNumOfNodes();[m
     myTree->numOfNodes = numOfNodes;[m
 [m
[36m@@ -30,7 +30,7 @@[m [mTree* Tree::createTree(const Session &session, int rootLabel) {[m
     for (int i = 0; i < myTree->numOfNodes; ++i) {[m
         myTree->ranks.push_back(0);[m
     }[m
[31m-    myTree->setRanks(&(myTree->ranks),myTree);[m
[32m+[m[32m    myTree->setRanks((myTree->ranks),myTree);[m
 [m
 [m
     delete visitedVertices;[m
[36m@@ -74,9 +74,10 @@[m [mvoid Tree::createChildrenTree(std::vector<bool>* visitedVertices,const Graph &g,[m
     delete neighboursOfRoot;[m
 }[m
 [m
[31m- Tree& Tree::getNewTree(TreeType type,int rootLabel) {[m
[32m+[m[32m Tree& Tree::getNewTree(const Session session,int rootLabel) {[m
[32m+[m[32m    TreeType type=session.getTreeType();[m
     if(type==Cycle)[m
[31m-        return *(new CycleTree(rootLabel,Session.currCycle));[m
[32m+[m[32m        return *(new CycleTree(rootLabel,session.getCurrCycle()));[m
     else if(type==MaxRank)[m
         return *(new MaxRankTree(rootLabel));[m
     else[m
[36m@@ -103,9 +104,22 @@[m [mvoid Tree::addChild(const Tree &child) {[m
 }[m
 [m
 int Tree::getRank() const {[m
[31m-    return children.size();[m
[32m+[m[32m    return (getRanks())[this->node];[m
 }[m
 [m
 int Tree::getRoot() const {return this->node;}[m
 [m
 const vector<Tree*> Tree::getChildren() const {return this->children;}[m
[32m+[m
[32m+[m[32mTree::~Tree() {[m
[32m+[m
[32m+[m[32m    delete ranks;[m
[32m+[m[32m    for (int i = 0; i < children.size(); ++i) {[m
[32m+[m[32m        delete(children[i]);[m
[32m+[m[32m    }[m
[32m+[m
[32m+[m[32m}[m
[32m+[m
[32m+[m[32mstd::vector<int> &Tree::getRanks() const {[m
[32m+[m[32m    return *ranks;[m
[32m+[m[32m}[m
[1mdiff --git a/Tree.h b/Tree.h[m
[1mindex 533672d..24183b8 100644[m
[1m--- a/Tree.h[m
[1m+++ b/Tree.h[m
[36m@@ -14,17 +14,19 @@[m [mpublic:[m
     const std::vector<Tree*> getChildren() const;[m
     int getRoot() const;[m
     int getRank() const;[m
[31m-    [m
[32m+[m[32m    virtual ~Tree();[m
 private:[m
     int node;[m
     std::vector<Tree*> children;[m
[31m-    static Tree& getNewTree(TreeType type,int rootLabel);[m
[32m+[m
[32m+[m[32m    static Tree& getNewTree(Session session,int rootLabel);[m
     void createChildrenTree(std::vector<bool>* visitedVertices,const Graph &g,TreeType type);[m
     void setRanks(std::vector<int>* ranks,Tree* tree);[m
 [m
 protected:[m
     int numOfNodes;[m
[31m-    std::vector<int> ranks;[m
[32m+[m[32m    std::vector<int>* ranks;[m
[32m+[m[32m    std::vector<int>& getRanks() const;[m
 [m
 };[m
 [m
[36m@@ -42,8 +44,8 @@[m [mpublic:[m
     virtual int traceTree();[m
 private:[m
     int maxRankTreeTrace();[m
[31m-    std::vector<int>* getMaxRankNode();[m
[31m-    std::vector<int>* getMaxRankChild();[m
[32m+[m[32m    int getMaxRankNode();[m
[32m+[m[32m    int getMaxRankChild();[m
 };[m
 [m
 class RootTree: public Tree{[m
[1mdiff --git a/cmake-build-debug/CMakeFiles/Progress/1 b/cmake-build-debug/CMakeFiles/Progress/1[m
[1mnew file mode 100644[m
[1mindex 0000000..7b4d68d[m
[1m--- /dev/null[m
[1m+++ b/cmake-build-debug/CMakeFiles/Progress/1[m
[36m@@ -0,0 +1 @@[m
[32m+[m[32mempty[m
\ No newline at end of file[m
[1mdiff --git a/cmake-build-debug/CMakeFiles/Progress/2 b/cmake-build-debug/CMakeFiles/Progress/2[m
[1mnew file mode 100644[m
[1mindex 0000000..7b4d68d[m
[1m--- /dev/null[m
[1m+++ b/cmake-build-debug/CMakeFiles/Progress/2[m
[36m@@ -0,0 +1 @@[m
[32m+[m[32mempty[m
\ No newline at end of file[m
[1mdiff --git a/cmake-build-debug/CMakeFiles/Progress/3 b/cmake-build-debug/CMakeFiles/Progress/3[m
[1mnew file mode 100644[m
[1mindex 0000000..7b4d68d[m
[1m--- /dev/null[m
[1m+++ b/cmake-build-debug/CMakeFiles/Progress/3[m
[36m@@ -0,0 +1 @@[m
[32m+[m[32mempty[m
\ No newline at end of file[m
[1mdiff --git a/cmake-build-debug/CMakeFiles/Progress/4 b/cmake-build-debug/CMakeFiles/Progress/4[m
[1mnew file mode 100644[m
[1mindex 0000000..7b4d68d[m
[1m--- /dev/null[m
[1m+++ b/cmake-build-debug/CMakeFiles/Progress/4[m
[36m@@ -0,0 +1 @@[m
[32m+[m[32mempty[m
\ No newline at end of file[m
[1mdiff --git a/cmake-build-debug/CMakeFiles/Progress/5 b/cmake-build-debug/CMakeFiles/Progress/5[m
[1mnew file mode 100644[m
[1mindex 0000000..7b4d68d[m
[1m--- /dev/null[m
[1m+++ b/cmake-build-debug/CMakeFiles/Progress/5[m
[36m@@ -0,0 +1 @@[m
[32m+[m[32mempty[m
\ No newline at end of file[m
[1mdiff --git a/cmake-build-debug/CMakeFiles/Progress/6 b/cmake-build-debug/CMakeFiles/Progress/6[m
[1mnew file mode 100644[m
[1mindex 0000000..7b4d68d[m
[1m--- /dev/null[m
[1m+++ b/cmake-build-debug/CMakeFiles/Progress/6[m
[36m@@ -0,0 +1 @@[m
[32m+[m[32mempty[m
\ No newline at end of file[m
[1mdiff --git a/cmake-build-debug/CMakeFiles/Progress/count.txt b/cmake-build-debug/CMakeFiles/Progress/count.txt[m
[1mnew file mode 100644[m
[1mindex 0000000..b4de394[m
[1m--- /dev/null[m
[1m+++ b/cmake-build-debug/CMakeFiles/Progress/count.txt[m
[36m@@ -0,0 +1 @@[m
[32m+[m[32m11[m
[1mdiff --git a/cmake-build-debug/CMakeFiles/VirusSpl.dir/Agent.cpp.o b/cmake-build-debug/CMakeFiles/VirusSpl.dir/Agent.cpp.o[m
[1mnew file mode 100644[m
[1mindex 0000000..0fd6f91[m
Binary files /dev/null and b/cmake-build-debug/CMakeFiles/VirusSpl.dir/Agent.cpp.o differ
[1mdiff --git a/cmake-build-debug/CMakeFiles/VirusSpl.dir/CXX.includecache b/cmake-build-debug/CMakeFiles/VirusSpl.dir/CXX.includecache[m
[1mnew file mode 100644[m
[1mindex 0000000..38e2ec8[m
[1m--- /dev/null[m
[1m+++ b/cmake-build-debug/CMakeFiles/VirusSpl.dir/CXX.includecache[m
[36m@@ -0,0 +1,440 @@[m
[32m+[m[32m#IncludeRegexLine: ^[ 	]*[#%][ 	]*(include|import)[ 	]*[<"]([^">]+)([">])[m
[32m+[m
[32m+[m[32m#IncludeRegexScan: ^.*$[m
[32m+[m
[32m+[m[32m#IncludeRegexComplain: ^$[m
[32m+[m
[32m+[m[32m#IncludeRegexTransform:[m[41m [m
[32m+[m
[32m+[m[32m/home/spl211/CLionProjects/VirusSpl/Agent.cpp[m
[32m+[m[32mAgent.h[m
[32m+[m[32m/home/spl211/CLionProjects/VirusSpl/Agent.h[m
[32m+[m
[32m+[m[32m/home/spl211/CLionProjects/VirusSpl/Agent.h[m
[32m+[m[32mvector[m
[32m+[m[32m-[m
[32m+[m[32mSession.h[m
[32m+[m[32m/home/spl211/CLionProjects/VirusSpl/Session.h[m
[32m+[m
[32m+[m[32m/home/spl211/CLionProjects/VirusSpl/ContactTracer.cpp[m
[32m+[m[32mTree.h[m
[32m+[m[32m/home/spl211/CLionProjects/VirusSpl/Tree.h[m
[32m+[m[32mAgent.h[m
[32m+[m[32m/home/spl211/CLionProjects/VirusSpl/Agent.h[m
[32m+[m
[32m+[m[32m/home/spl211/CLionProjects/VirusSpl/CycleTree.cpp[m
[32m+[m[32mTree.h[m
[32m+[m[32m/home/spl211/CLionProjects/VirusSpl/Tree.h[m
[32m+[m[32mvector[m
[32m+[m[32m/home/spl211/CLionProjects/VirusSpl/vector[m
[32m+[m
[32m+[m[32m/home/spl211/CLionProjects/VirusSpl/Graph.cpp[m
[32m+[m[32mGraph.h[m
[32m+[m[32m/home/spl211/CLionProjects/VirusSpl/Graph.h[m
[32m+[m
[32m+[m[32m/home/spl211/CLionProjects/VirusSpl/Graph.h[m
[32m+[m[32mvector[m
[32m+[m[32m-[m
[32m+[m[32mqueue[m
[32m+[m[32m-[m
[32m+[m
[32m+[m[32m/home/spl211/CLionProjects/VirusSpl/MaxRankTree.cpp[m
[32m+[m[32mTree.h[m
[32m+[m[32m/home/spl211/CLionProjects/VirusSpl/Tree.h[m
[32m+[m[32mvector[m
[32m+[m[32m/home/spl211/CLionProjects/VirusSpl/vector[m
[32m+[m
[32m+[m[32m/home/spl211/CLionProjects/VirusSpl/RootTree.cpp[m
[32m+[m[32mTree.h[m
[32m+[m[32m/home/spl211/CLionProjects/VirusSpl/Tree.h[m
[32m+[m
[32m+[m[32m/home/spl211/CLionProjects/VirusSpl/Session.cpp[m
[32m+[m[32mSession.h[m
[32m+[m[32m/home/spl211/CLionProjects/VirusSpl/Session.h[m
[32m+[m[32mvector[m
[32m+[m[32m-[m
[32m+[m[32mAgent.h[m
[32m+[m[32m/home/spl211/CLionProjects/VirusSpl/Agent.h[m
[32m+[m[32mjson.hpp[m
[32m+[m[32m/home/spl211/CLionProjects/VirusSpl/json.hpp[m
[32m+[m[32mfstream[m
[32m+[m[32m-[m
[32m+[m
[32m+[m[32m/home/spl211/CLionProjects/VirusSpl/Session.h[m
[32m+[m[32mvector[m
[32m+[m[32m-[m
[32m+[m[32mstring[m
[32m+[m[32m-[m
[32m+[m[32mqueue[m
[32m+[m[32m-[m
[32m+[m[32mGraph.h[m
[32m+[m[32m/home/spl211/CLionProjects/VirusSpl/Graph.h[m
[32m+[m[32mmap[m
[32m+[m[32m-[m
[32m+[m[32mjson.hpp[m
[32m+[m[32m/home/spl211/CLionProjects/VirusSpl/json.hpp[m
[32m+[m
[32m+[m[32m/home/spl211/CLionProjects/VirusSpl/Tree.cpp[m
[32m+[m[32mTree.h[m
[32m+[m[32m/home/spl211/CLionProjects/VirusSpl/Tree.h[m
[32m+[m[32mGraph.h[m
[32m+[m[32m/home/spl211/CLionProjects/VirusSpl/Graph.h[m
[32m+[m[32mvector[m
[32m+[m[32m/home/spl211/CLionProjects/VirusSpl/vector[m
[32m+[m[32mSession.h[m
[32m+[m[32m/home/spl211/CLionProjects/VirusSpl/Session.h[m
[32m+[m
[32m+[m[32m/home/spl211/CLionProjects/VirusSpl/Tree.h[m
[32m+[m[32mvector[m
[32m+[m[32m-[m
[32m+[m[32mSession.h[m
[32m+[m[32m/home/spl211/CLionProjects/VirusSpl/Session.h[m
[32m+[m
[32m+[m[32m/home/spl211/CLionProjects/VirusSpl/Virus.cpp[m
[32m+[m[32mvector[m
[32m+[m[32m-[m
[32m+[m[32mSession.h[m
[32m+[m[32m/home/spl211/CLionProjects/VirusSpl/Session.h[m
[32m+[m[32mAgent.h[m
[32m+[m[32m/home/spl211/CLionProjects/VirusSpl/Agent.h[m
[32m+[m
[32m+[m[32m/home/spl211/CLionProjects/VirusSpl/json.hpp[m
[32m+[m[32malgorithm[m
[32m+[m[32m-[m
[32m+[m[32mcassert[m
[32m+[m[32m-[m
[32m+[m[32mciso646[m
[32m+[m[32m-[m
[32m+[m[32mcstddef[m
[32m+[m[32m-[m
[32m+[m[32mfunctional[m
[32m+[m[32m-[m
[32m+[m[32minitializer_list[m
[32m+[m[32m-[m
[32m+[m[32miosfwd[m
[32m+[m[32m-[m
[32m+[m[32miterator[m
[32m+[m[32m-[m
[32m+[m[32mmemory[m
[32m+[m[32m-[m
[32m+[m[32mnumeric[m
[32m+[m[32m-[m
[32m+[m[32mstring[m
[32m+[m[32m-[m
[32m+[m[32mutility[m
[32m+[m[32m-[m
[32m+[m[32mvector[m
[32m+[m[32m-[m
[32m+[m[32mutility[m
[32m+[m[32m-[m
[32m+[m[32malgorithm[m
[32m+[m[32m-[m
[32m+[m[32marray[m
[32m+[m[32m-[m
[32m+[m[32mciso646[m
[32m+[m[32m-[m
[32m+[m[32mforward_list[m
[32m+[m[32m-[m
[32m+[m[32miterator[m
[32m+[m[32m-[m
[32m+[m[32mmap[m
[32m+[m[32m-[m
[32m+[m[32mstring[m
[32m+[m[32m-[m
[32m+[m[32mtuple[m
[32m+[m[32m-[m
[32m+[m[32mtype_traits[m
[32m+[m[32m-[m
[32m+[m[32munordered_map[m
[32m+[m[32m-[m
[32m+[m[32mutility[m
[32m+[m[32m-[m
[32m+[m[32mvalarray[m
[32m+[m[32m-[m
[32m+[m[32mexception[m
[32m+[m[32m-[m
[32m+[m[32mstdexcept[m
[32m+[m[32m-[m
[32m+[m[32mstring[m
[32m+[m[32m-[m
[32m+[m[32mcstddef[m
[32m+[m[32m-[m
[32m+[m[32mutility[m
[32m+[m[32m-[m
[32m+[m[32mstdint.h[m
[32m+[m[32m-[m
[32m+[m[32mstdint.h[m
[32m+[m[32m-[m
[32m+[m[32mcstdlib[m
[32m+[m[32m-[m
[32m+[m[32mciso646[m
[32m+[m[32m-[m
[32m+[m[32mcstddef[m
[32m+[m[32m-[m
[32m+[m[32mtype_traits[m
[32m+[m[32m-[m
[32m+[m[32mciso646[m
[32m+[m[32m-[m
[32m+[m[32mlimits[m
[32m+[m[32m-[m
[32m+[m[32mtype_traits[m
[32m+[m[32m-[m
[32m+[m[32mutility[m
[32m+[m[32m-[m
[32m+[m[32miterator[m
[32m+[m[32m-[m
[32m+[m[32mtype_traits[m
[32m+[m[32m-[m
[32m+[m[32mcstdint[m
[32m+[m[32m-[m
[32m+[m[32mmap[m
[32m+[m[32m-[m
[32m+[m[32mmemory[m
[32m+[m[32m-[m
[32m+[m[32mstring[m
[32m+[m[32m-[m
[32m+[m[32mvector[m
[32m+[m[32m-[m
[32m+[m[32marray[m
[32m+[m[32m-[m
[32m+[m[32mciso646[m
[32m+[m[32m-[m
[32m+[m[32mcstddef[m
[32m+[m[32m-[m
[32m+[m[32mcstdint[m
[32m+[m[32m-[m
[32m+[m[32mstring[m
[32m+[m[32m-[m
[32m+[m[32malgorithm[m
[32m+[m[32m-[m
[32m+[m[32mciso646[m
[32m+[m[32m-[m
[32m+[m[32miterator[m
[32m+[m[32m-[m
[32m+[m[32mstring[m
[32m+[m[32m-[m
[32m+[m[32mtuple[m
[32m+[m[32m-[m
[32m+[m[32mtype_traits[m
[32m+[m[32m-[m
[32m+[m[32mutility[m
[32m+[m[32m-[m
[32m+[m[32mvalarray[m
[32m+[m[32m-[m
[32m+[m[32mvector[m
[32m+[m[32m-[m
[32m+[m[32mcstddef[m
[32m+[m[32m-[m
[32m+[m[32miterator[m
[32m+[m[32m-[m
[32m+[m[32mstring[m
[32m+[m[32m-[m
[32m+[m[32mtuple[m
[32m+[m[32m-[m
[32m+[m[32malgorithm[m
[32m+[m[32m-[m
[32m+[m[32marray[m
[32m+[m[32m-[m
[32m+[m[32mcassert[m
[32m+[m[32m-[m
[32m+[m[32mcmath[m
[32m+[m[32m-[m
[32m+[m[32mcstddef[m
[32m+[m[32m-[m
[32m+[m[32mcstdint[m
[32m+[m[32m-[m
[32m+[m[32mcstdio[m
[32m+[m[32m-[m
[32m+[m[32mcstring[m
[32m+[m[32m-[m
[32m+[m[32miterator[m
[32m+[m[32m-[m
[32m+[m[32mlimits[m
[32m+[m[32m-[m
[32m+[m[32mstring[m
[32m+[m[32m-[m
[32m+[m[32mutility[m
[32m+[m[32m-[m
[32m+[m[32marray[m
[32m+[m[32m-[m
[32m+[m[32mcassert[m
[32m+[m[32m-[m
[32m+[m[32mcstddef[m
[32m+[m[32m-[m
[32m+[m[32mcstdio[m
[32m+[m[32m-[m
[32m+[m[32mcstring[m
[32m+[m[32m-[m
[32m+[m[32mistream[m
[32m+[m[32m-[m
[32m+[m[32miterator[m
[32m+[m[32m-[m
[32m+[m[32mmemory[m
[32m+[m[32m-[m
[32m+[m[32mnumeric[m
[32m+[m[32m-[m
[32m+[m[32mstring[m
[32m+[m[32m-[m
[32m+[m[32mtype_traits[m
[32m+[m[32m-[m
[32m+[m[32mutility[m
[32m+[m[32m-[m
[32m+[m[32mcassert[m
[32m+[m[32m-[m
[32m+[m[32mcstddef[m
[32m+[m[32m-[m
[32m+[m[32mstring[m
[32m+[m[32m-[m
[32m+[m[32mutility[m
[32m+[m[32m-[m
[32m+[m[32mvector[m
[32m+[m[32m-[m
[32m+[m[32mcstdint[m
[32m+[m[32m-[m
[32m+[m[32mutility[m
[32m+[m[32m-[m
[32m+[m[32mstring[m
[32m+[m[32m-[m
[32m+[m[32marray[m
[32m+[m[32m-[m
[32m+[m[32mclocale[m
[32m+[m[32m-[m
[32m+[m[32mcstddef[m
[32m+[m[32m-[m
[32m+[m[32mcstdio[m
[32m+[m[32m-[m
[32m+[m[32mcstdlib[m
[32m+[m[32m-[m
[32m+[m[32minitializer_list[m
[32m+[m[32m-[m
[32m+[m[32mstring[m
[32m+[m[32m-[m
[32m+[m[32mutility[m
[32m+[m[32m-[m
[32m+[m[32mvector[m
[32m+[m[32m-[m
[32m+[m[32mcassert[m
[32m+[m[32m-[m
[32m+[m[32mcmath[m
[32m+[m[32m-[m
[32m+[m[32mcstdint[m
[32m+[m[32m-[m
[32m+[m[32mfunctional[m
[32m+[m[32m-[m
[32m+[m[32mstring[m
[32m+[m[32m-[m
[32m+[m[32mutility[m
[32m+[m[32m-[m
[32m+[m[32mvector[m
[32m+[m[32m-[m
[32m+[m[32mcstddef[m
[32m+[m[32m-[m
[32m+[m[32mlimits[m
[32m+[m[32m-[m
[32m+[m[32mciso646[m
[32m+[m[32m-[m
[32m+[m[32miterator[m
[32m+[m[32m-[m
[32m+[m[32mtype_traits[m
[32m+[m[32m-[m
[32m+[m[32mcstddef[m
[32m+[m[32m-[m
[32m+[m[32miterator[m
[32m+[m[32m-[m
[32m+[m[32mutility[m
[32m+[m[32m-[m
[32m+[m[32malgorithm[m
[32m+[m[32m-[m
[32m+[m[32mcassert[m
[32m+[m[32m-[m
[32m+[m[32mcctype[m
[32m+[m[32m-[m
[32m+[m[32mnumeric[m
[32m+[m[32m-[m
[32m+[m[32mstring[m
[32m+[m[32m-[m
[32m+[m[32mutility[m
[32m+[m[32m-[m
[32m+[m[32mvector[m
[32m+[m[32m-[m
[32m+[m[32minitializer_list[m
[32m+[m[32m-[m
[32m+[m[32mutility[m
[32m+[m[32m-[m
[32m+[m[32malgorithm[m
[32m+[m[32m-[m
[32m+[m[32marray[m
[32m+[m[32m-[m
[32m+[m[32mcstdint[m
[32m+[m[32m-[m
[32m+[m[32mcstring[m
[32m+[m[32m-[m
[32m+[m[32mlimits[m
[32m+[m[32m-[m
[32m+[m[32mstring[m
[32m+[m[32m-[m
[32m+[m[32malgorithm[m
[32m+[m[32m-[m
[32m+[m[32mcstddef[m
[32m+[m[32m-[m
[32m+[m[32mios[m
[32m+[m[32m-[m
[32m+[m[32miterator[m
[32m+[m[32m-[m
[32m+[m[32mmemory[m
[32m+[m[32m-[m
[32m+[m[32mostream[m
[32m+[m[32m-[m
[32m+[m[32mstring[m
[32m+[m[32m-[m
[32m+[m[32mvector[m
[32m+[m[32m-[m
[32m+[m[32malgorithm[m
[32m+[m[32m-[m
[32m+[m[32marray[m
[32m+[m[32m-[m
[32m+[m[32mcassert[m
[32m+[m[32m-[m
[32m+[m[32mciso646[m
[32m+[m[32m-[m
[32m+[m[32mclocale[m
[32m+[m[32m-[m
[32m+[m[32mcmath[m
[32m+[m[32m-[m
[32m+[m[32mcstddef[m
[32m+[m[32m-[m
[32m+[m[32mcstdint[m
[32m+[m[32m-[m
[32m+[m[32mcstdio[m
[32m+[m[32m-[m
[32m+[m[32mlimits[m
[32m+[m[32m-[m
[32m+[m[32mstring[m
[32m+[m[32m-[m
[32m+[m[32mtype_traits[m
[32m+[m[32m-[m
[32m+[m[32mutility[m
[32m+[m[32m-[m
[32m+[m[32marray[m
[32m+[m[32m-[m
[32m+[m[32mcassert[m
[32m+[m[32m-[m
[32m+[m[32mciso646[m
[32m+[m[32m-[m
[32m+[m[32mcmath[m
[32m+[m[32m-[m
[32m+[m[32mcstdint[m
[32m+[m[32m-[m
[32m+[m[32mcstring[m
[32m+[m[32m-[m
[32m+[m[32mlimits[m
[32m+[m[32m-[m
[32m+[m[32mtype_traits[m
[32m+[m[32m-[m
[32m+[m
[32m+[m[32m/home/spl211/CLionProjects/VirusSpl/main.cpp[m
[32m+[m[32miostream[m
[32m+[m[32m-[m
[32m+[m[32mSession.h[m
[32m+[m[32m/home/spl211/CLionProjects/VirusSpl/Session.h[m
[32m+[m
[1mdiff --git a/cmake-build-debug/CMakeFiles/VirusSpl.dir/Graph.cpp.o b/cmake-build-debug/CMakeFiles/VirusSpl.dir/Graph.cpp.o[m
[1mnew file mode 100644[m
[1mindex 0000000..24695d0[m
Binary files /dev/null and b/cmake-build-debug/CMakeFiles/VirusSpl.dir/Graph.cpp.o differ
[1mdiff --git a/cmake-build-debug/CMakeFiles/VirusSpl.dir/Session.cpp.o b/cmake-build-debug/CMakeFiles/VirusSpl.dir/Session.cpp.o[m
[1mnew file mode 100644[m
[1mindex 0000000..cc00ccb[m
Binary files /dev/null and b/cmake-build-debug/CMakeFiles/VirusSpl.dir/Session.cpp.o differ
[1mdiff --git a/cmake-build-debug/CMakeFiles/VirusSpl.dir/Virus.cpp.o b/cmake-build-debug/CMakeFiles/VirusSpl.dir/Virus.cpp.o[m
[1mnew file mode 100644[m
[1mindex 0000000..478412b[m
Binary files /dev/null and b/cmake-build-debug/CMakeFiles/VirusSpl.dir/Virus.cpp.o differ
[1mdiff --git a/cmake-build-debug/CMakeFiles/VirusSpl.dir/depend.internal b/cmake-build-debug/CMakeFiles/VirusSpl.dir/depend.internal[m
[1mnew file mode 100644[m
[1mindex 0000000..018d99b[m
[1m--- /dev/null[m
[1m+++ b/cmake-build-debug/CMakeFiles/VirusSpl.dir/depend.internal[m
[36m@@ -0,0 +1,60 @@[m
[32m+[m[32m# CMAKE generated file: DO NOT EDIT![m
[32m+[m[32m# Generated by "Unix Makefiles" Generator, CMake Version 3.17[m
[32m+[m
[32m+[m[32mCMakeFiles/VirusSpl.dir/Agent.cpp.o[m
[32m+[m[32m /home/spl211/CLionProjects/VirusSpl/Agent.cpp[m
[32m+[m[32m /home/spl211/CLionProjects/VirusSpl/Agent.h[m
[32m+[m[32m /home/spl211/CLionProjects/VirusSpl/Graph.h[m
[32m+[m[32m /home/spl211/CLionProjects/VirusSpl/Session.h[m
[32m+[m[32m /home/spl211/CLionProjects/VirusSpl/json.hpp[m
[32m+[m[32mCMakeFiles/VirusSpl.dir/ContactTracer.cpp.o[m
[32m+[m[32m /home/spl211/CLionProjects/VirusSpl/Agent.h[m
[32m+[m[32m /home/spl211/CLionProjects/VirusSpl/ContactTracer.cpp[m
[32m+[m[32m /home/spl211/CLionProjects/VirusSpl/Graph.h[m
[32m+[m[32m /home/spl211/CLionProjects/VirusSpl/Session.h[m
[32m+[m[32m /home/spl211/CLionProjects/VirusSpl/Tree.h[m
[32m+[m[32m /home/spl211/CLionProjects/VirusSpl/json.hpp[m
[32m+[m[32mCMakeFiles/VirusSpl.dir/CycleTree.cpp.o[m
[32m+[m[32m /home/spl211/CLionProjects/VirusSpl/CycleTree.cpp[m
[32m+[m[32m /home/spl211/CLionProjects/VirusSpl/Graph.h[m
[32m+[m[32m /home/spl211/CLionProjects/VirusSpl/Session.h[m
[32m+[m[32m /home/spl211/CLionProjects/VirusSpl/Tree.h[m
[32m+[m[32m /home/spl211/CLionProjects/VirusSpl/json.hpp[m
[32m+[m[32mCMakeFiles/VirusSpl.dir/Graph.cpp.o[m
[32m+[m[32m /home/spl211/CLionProjects/VirusSpl/Graph.cpp[m
[32m+[m[32m /home/spl211/CLionProjects/VirusSpl/Graph.h[m
[32m+[m[32mCMakeFiles/VirusSpl.dir/MaxRankTree.cpp.o[m
[32m+[m[32m /home/spl211/CLionProjects/VirusSpl/Graph.h[m
[32m+[m[32m /home/spl211/CLionProjects/VirusSpl/MaxRankTree.cpp[m
[32m+[m[32m /home/spl211/CLionProjects/VirusSpl/Session.h[m
[32m+[m[32m /home/spl211/CLionProjects/VirusSpl/Tree.h[m
[32m+[m[32m /home/spl211/CLionProjects/VirusSpl/json.hpp[m
[32m+[m[32mCMakeFiles/VirusSpl.dir/RootTree.cpp.o[m
[32m+[m[32m /home/spl211/CLionProjects/VirusSpl/Graph.h[m
[32m+[m[32m /home/spl211/CLionProjects/VirusSpl/RootTree.cpp[m
[32m+[m[32m /home/spl211/CLionProjects/VirusSpl/Session.h[m
[32m+[m[32m /home/spl211/CLionProjects/VirusSpl/Tree.h[m
[32m+[m[32m /home/spl211/CLionProjects/VirusSpl/json.hpp[m
[32m+[m[32mCMakeFiles/VirusSpl.dir/Session.cpp.o[m
[32m+[m[32m /home/spl211/CLionProjects/VirusSpl/Agent.h[m
[32m+[m[32m /home/spl211/CLionProjects/VirusSpl/Graph.h[m
[32m+[m[32m /home/spl211/CLionProjects/VirusSpl/Session.cpp[m
[32m+[m[32m /home/spl211/CLionProjects/VirusSpl/Session.h[m
[32m+[m[32m /home/spl211/CLionProjects/VirusSpl/json.hpp[m
[32m+[m[32mCMakeFiles/VirusSpl.dir/Tree.cpp.o[m
[32m+[m[32m /home/spl211/CLionProjects/VirusSpl/Graph.h[m
[32m+[m[32m /home/spl211/CLionProjects/VirusSpl/Session.h[m
[32m+[m[32m /home/spl211/CLionProjects/VirusSpl/Tree.cpp[m
[32m+[m[32m /home/spl211/CLionProjects/VirusSpl/Tree.h[m
[32m+[m[32m /home/spl211/CLionProjects/VirusSpl/json.hpp[m
[32m+[m[32mCMakeFiles/VirusSpl.dir/Virus.cpp.o[m
[32m+[m[32m /home/spl211/CLionProjects/VirusSpl/Agent.h[m
[32m+[m[32m /home/spl211/CLionProjects/VirusSpl/Graph.h[m
[32m+[m[32m /home/spl211/CLionProjects/VirusSpl/Session.h[m
[32m+[m[32m /home/spl211/CLionProjects/VirusSpl/Virus.cpp[m
[32m+[m[32m /home/spl211/CLionProjects/VirusSpl/json.hpp[m
[32m+[m[32mCMakeFiles/VirusSpl.dir/main.cpp.o[m
[32m+[m[32m /home/spl211/CLionProjects/VirusSpl/Graph.h[m
[32m+[m[32m /home/spl211/CLionProjects/VirusSpl/Session.h[m
[32m+[m[32m /home/spl211/CLionProjects/VirusSpl/json.hpp[m
[32m+[m[32m /home/spl211/CLionProjects/VirusSpl/main.cpp[m
[1mdiff --git a/cmake-build-debug/CMakeFiles/VirusSpl.dir/main.cpp.o b/cmake-build-debug/CMakeFiles/VirusSpl.dir/main.cpp.o[m
[1mnew file mode 100644[m
[1mindex 0000000..2cc41d9[m
Binary files /dev/null and b/cmake-build-debug/CMakeFiles/VirusSpl.dir/main.cpp.o differ
