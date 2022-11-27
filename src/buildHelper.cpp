#include "buildHelper.h"

void buildHelper::insertNode(vector<string> line) { Node v(line); }

void buildHelper::insertEdge(vector<string> otherInfo, vector<long> authors){
    long source;
    long dest;
    vector<string> videos;
    vector<long> views;
    vector<long> likes;
    vector<long> coins;


    if(authors.size() > 1){ //have collaboration
        for(unsigned int i = 0; i < authors.size()-1; i++){
            for(unsigned int j = 1; j < authors.size(); j++){
                source = authors.at(i);
                dest = authors.at(j);
                videos.push_back(otherInfo.at(0));
                views.push_back(std::stol(otherInfo.at(1)));
                likes.push_back(std::stol(otherInfo.at(2)));
                coins.push_back(std::stol(otherInfo.at(3)));
                
                Edge e(source, dest, videos, views, likes, coins);
            }
        }

    }
}

