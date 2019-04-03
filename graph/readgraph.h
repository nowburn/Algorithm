#include<iostream>
#include<string>
#include<fstream>
#include<sstream>
#include<cassert>

using namespace std;

template<typename Graph>
class ReadGraph{

public:
    ReadGraph(Graph &graph, const string &filename){
        ifstream file(filename);
        string line;
        int V, E;

        assert(file.is_open)

        assert(getline(file, line));
        stringstream ss(line);
        ss>>V>>E;

        
    }
}