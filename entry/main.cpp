#include "../src/buildGraph.h"
#include <iostream>
using namespace std;

int main() {
  // buildGraph out("../data/testreadauthor.csv", "../data/testReadVideo.csv");
  buildGraph out("../data/authorData.csv", "../data/test.csv");
  vector<vector<Edge>> mst = out.Kruskal();
  vector<Edge> biggest_mst = mst[0];
  for (size_t i = 0; i < mst.size(); i++) {
    if (biggest_mst.size() < mst[i].size()) {
      biggest_mst = mst[i];
    }
  }
  cout << "All edges of MST in biggest graph "
       << "(uid-uid"
       << " / BVID) :" << endl;
  for (auto edge : biggest_mst) {
    int node1 = edge.source;
    int node2 = edge.dest;
    string relate_bvid = edge.getVideos().at(edge.getWeight().second);
    cout << "   " << node1 << "-" << node2 << " / " << relate_bvid << endl;
  }
}