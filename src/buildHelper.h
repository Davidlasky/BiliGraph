#pragma once
#include "edge.h"
#include "node.h"
#include <algorithm>
#include <cctype>
#include <cmath>
#include <map>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

class buildHelper {
public:
  void insertNode(vector<string> line);
  void insertEdge(vector<string> otherInfo, vector<int> authors);
  map<int, node> uidToNode; // link uid to node

  // egdge_list for kruskal
  vector<Edge> edges_list;
};
