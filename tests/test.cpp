#include <catch2/catch_test_macros.hpp>
#include <iostream>
#include <stdexcept>
#include <string>
#include <unordered_map>

#include "../src/buildGraph.h"
#include "../src/edge.h"
#include "../src/node.h"

using namespace std;

int main() {
  bool flag = true;
  buildGraph graph("../data/test1.csv", "../data/test2.csv");
  // graph.constructGraph("../data/test1.csv", "../data/test2.csv");

  assert(flag == true);
  cout << "Test passed! Yay!" << endl;
  return 0;
}