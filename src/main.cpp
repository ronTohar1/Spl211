#include <iostream>
#include "../include/Session.h"

using namespace std;

int main(int argc, char** argv){
    if(argc != 2){
        cout << "usage cTrace <config_path>" << endl;
        return 0;
    }
     Session sess(argv[1]);
//    Session sess("../config4.json");
    sess.simulate();
    return 0;
}

//#include <iostream>
//#include <fstream>
//#include "../include/Tree.h"
//
//#define JSON_PATH "output.json"
//
//using namespace std;
//
//int tree_exp1(){
//    MaxRankTree t(1);
//    MaxRankTree t2(2);
//    t2.addChild(MaxRankTree(3));
//    t2.addChild(MaxRankTree(4));
//    t2.addChild(MaxRankTree(5));
//    t.addChild(t2);
//    t.addChild(MaxRankTree(6));
//    return t.traceTree();
//}
//
//
//int main(int argc, char** argv){
//    nlohmann::json j;
//    j["tree1"] = tree_exp1();
//    std::ofstream o(JSON_PATH);
//    o << j << endl;
//    return 0;
//}