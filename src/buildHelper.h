#pragma once
#include "node.h"
#include "edge.h"

using namespace std;

class buildHelper{
    public:
        void insertNode(vector<string> line);
        void insertEdge(vector<string> otherInfo, vector<long> authors);

};
