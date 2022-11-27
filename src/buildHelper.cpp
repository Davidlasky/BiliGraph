#include "buildHelper.h"

void buildHelper::insertNode(vector<string> line) {
  Node v(line);
  uidToNode.insert(pair<int, Node>(v.uid, v));
}

void buildHelper::insertEdge(vector<string> otherInfo, vector<int> authors) {
  int source;
  int dest;
  vector<string> videos;
  vector<int> views;
  vector<int> likes;
  vector<int> coins;

  if (authors.size() > 1) { // have collaboration
    for (unsigned int i = 0; i < authors.size() - 1; i++) {
      for (unsigned int j = 1; j < authors.size(); j++) {
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
