#include "../src/buildGraph.h"
#include <iostream>
using namespace std;

int main() {
  buildGraph out("../data/authorData.csv", "../data/test.csv");

  // output for BFS
  cout << "Running BFS" << endl;
  vector<vector<int>> graph_list = out.BFS();
  for (size_t i = 0; i < graph_list.size(); i++) {
    cout << "Graph " << i + 1 << "(traverse uid) : ";
    for (size_t j = 0; j < graph_list[i].size(); j++) {
      cout << graph_list[i][j] << " ";
    }
    cout << "\n";
  }
  cout << "\n"
       << "\n";

  // output for Kruskal
  cout << "Running Kruskal" << endl;
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
  for (size_t i = 0; i < biggest_mst.size() - 1; i++) {
    auto edge = biggest_mst[i];
    // for (auto edge : biggest_mst) {
    int node1 = edge.source;
    int node2 = edge.dest;
    string relate_bvid = edge.getVideos().at(edge.getWeight().second);
    cout << node1 << "-" << node2 << " / " << relate_bvid << " , ";
  }
  auto last_node = biggest_mst.back();
  string last_bvid = last_node.getVideos().at(last_node.getWeight().second);
  cout << last_node.source << "-" << last_node.dest << " / " << last_bvid;
  cout << "\n"
       << "\n";

  // output for Betweenness Centrality
  cout << "Running Betweeness Centrality" << endl;


  buildGraph graph("../data/authorData_small.csv", "../data/test_small.csv");
  vector<vector<int>> bfs_mapping = graph.BFS();
  vector<int> bigMap = bfs_mapping.at(0);
  map<int, int> centeralness = graph.shortestPath(bigMap);

  cout << "All nodes UID and its 'centrality': " << std::endl;

  for(auto const& pair: centeralness){
    std::cout << "{" << pair.first << ":" << pair.second << "}\n";
  }

  cout << "\n" << "\n";
}