#pragma once
#include <string>

class buildGraph {
    public:
        buildGraph(const string &authorFile, const string &videoFile);
    //call bGraph.insertNode and bGraph.insertEdge
        void constructGraph();
        void insertAuthor();
        void insertVideo();


    private:
        string authorFile_;
        string videoFile_;
        buildHelper bGraph;

};