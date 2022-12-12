#include "buildHelper.h"

void buildHelper::insertNode(vector<string> line) {
  node v(line);
  uidToNode.insert(pair<int, node>(v.uid, v));
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

  

  for (unsigned int i = 0; i < authors.size(); i++) {
    for (unsigned int j = 0; j < authors.size(); j++) {

      source = authors.at(i);
      dest = authors.at(j);
      
      if(i == j) {
        //break out if same author
        continue;
      }


      vector<double> affects;

  
      double impact;
      if(uidToNode[source].views == 0 && uidToNode[dest].views == 0){
        impact = std::stoi(otherInfo.at(1));
      } else if (uidToNode[source].views == 0 || uidToNode[dest].views == 0){
        impact = std::stoi(otherInfo.at(1))/ ((uidToNode[source].views + uidToNode[dest].views));
      } else {
        impact = std::stoi(otherInfo.at(1))/ ((uidToNode[source].views + uidToNode[dest].views)/2);
      }

      affects.push_back(impact);


      Edge e(source, dest, videos, views, likes, coins, affects); 
     

      if (uidToNode[source].neighbors.find(dest) ==
          uidToNode[source].neighbors.end()) {
            uidToNode[source].neighbors.insert(pair<int, Edge>(dest, e));

      } else {
        Edge& temp = uidToNode[source].neighbors[dest];
        temp.addVideo(otherInfo.at(0));
        temp.addViews(std::stoi(otherInfo.at(1)));
        temp.addLikes(std::stoi(otherInfo.at(2)));
        temp.addCoins(std::stoi(otherInfo.at(3)));

        temp.addAffect(impact);
      
      }
    }

  }


}
