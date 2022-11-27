#include "buildGraph.h"
#include "buildHelper.h"

using namespace std;

buildGraph::buildGraph(const string &authorFile, const string &videoFile){
    authorFile_ = authorFile;
    videoFile_ = videoFile;
    constructGraph();
}

void buildGraph::constructGraph(){
    insertAuthor();
    insertVideo();
}


void buildGraph::insertAuthor(){

}

void buildGraph::insertVideo(){

}