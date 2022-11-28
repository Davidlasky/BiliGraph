#include "buildHelper.h"

void buildHelper::insertNode(vector<string> line) {
  Node v(line);
  uidToNode.insert(pair<int, Node>(v.uid, v));
}

void buildHelper::insertEdge(vector<string> otherInfo, vector<int> authors) {
  int source;
  int dest;
  vector<string> videos;
  videos.push_back(otherInfo.at(0));
  vector<int> views;
  views.push_back(std::stoi(otherInfo.at(1)));
  vector<int> likes;
  likes.push_back(std::stoi(otherInfo.at(2)));
  vector<int> coins;
  coins.push_back(std::stoi(otherInfo.at(3)));

  if (authors.size() > 1) { // have collaboration
    for (unsigned int i = 0; i < authors.size() - 1; i++) {
      for (unsigned int j = 1; j < authors.size(); j++) {
        source = authors.at(i);
        dest = authors.at(j);

        Edge e(source, dest, videos, views, likes, coins);
      }
    }
  }
}
