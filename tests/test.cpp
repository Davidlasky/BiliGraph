#include "../src/buildGraph.h"
#include "../src/buildHelper.h"
#include "../src/edge.h"
#include "../src/node.h"
//#include "catch.hpp"

#include <algorithm>
#include <catch2/catch_test_macros.hpp>
#include <iostream>
#include <set>
#include <stdexcept>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;
/*
int main() {

  // TEST 2: correlation videos between two people
  cout << "-------Test 2: Check correlated videos between 2 people-------"
       << std::endl;
  buildGraph graph("../data/authorData_small.csv", "../data/test_small.csv");
  vector<string> corrVideos = {"BV1HF411T7oV", "BV1eY411P7kW", "BV1XZ4y1y7du",
                               "BV1mY4y1H7wp", "BV1QT4y1e79k"};
  assert(graph.bGraph.uidToNode[13354765].neighbors[7552204].getVideos() ==
         corrVideos);
  cout << "Correlation videos passed!!" << endl;
  std::string output = "";
  for (unsigned int i = 0; i < corrVideos.size(); i++) {
    output += corrVideos.at(i);
    output += ",";
  }
  cout << "Videos are: " << output << std::endl;

  cout << "--------Test 3: Check 1 person's neighbor ----------" << std::endl;
  std::vector<int> temp;
  // std::string output = "";
  auto neighbor_temp = graph.bGraph.uidToNode[454143774].neighbors;
  std::for_each(neighbor_temp.begin(), neighbor_temp.end(),
                [&temp](const std::map<int, Edge>::value_type &p) {
                  temp.push_back(p.first);
                });
  std::vector<int> correctVect = {32708543, 304578055, 1848018, 350632501};
  assert(temp == correctVect);

  cout << "Check neighbor passed!" << std::endl;
  cout << "----------------------------------------------------" << std::endl;

  buildGraph wholeGraph("../data/authorData.csv", "../data/test.csv");
  vector<vector<int>> bfs_mapping = wholeGraph.BFS();
}
*/
TEST_CASE("ckeck BFS", "[weight=1]") {
  buildGraph graph("../data/authorData.csv", "../data/test2.csv");
  vector<vector<int>> bfs_mapping = graph.BFS();
  bool flag1 = false;
  bool flag2 = false;
  bool flag3 = false;
  for (unsigned int i = 0; i < bfs_mapping.size(); i++) {
    for (unsigned int j = 0; j < bfs_mapping.at(i).size(); j++) {
      if (bfs_mapping.at(i).at(j) == 282994) {
        flag1 = true;
      }
      if (bfs_mapping.at(i).at(j) == 297344797) {
        flag2 = true;
      }
      if (bfs_mapping.at(i).at(j) == 1) {
        flag3 = true;
      }
    }
  }
  REQUIRE(flag1 == true);
  REQUIRE(flag2 == true);
  REQUIRE(flag3 == false);
}
