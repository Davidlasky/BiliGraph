#pragma once
#include "buildHelper.h"
#include "disjointset.h"

#include <algorithm>
#include <cassert>
#include <fstream>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <utility>
#include <vector>
class buildGraph {
public:
  buildGraph(const string authorFile, const string videoFile);
  // call bGraph.insertNode and bGraph.insertEdge
  void constructGraph(const string &authorFile, const string &videoFile);
  void insertAuthor(const string &authorFile);
  void insertVideo(const string &videoFile);

  // for test
  vector<vector<string>> author_ckecklist;
  vector<vector<string>> video_checklist;
  buildHelper bGraph;

  // BFS

  vector<int> BFS_helper(int start, vector<int> &nonVisited);
  vector<vector<int>> BFS();

  // Kruskal
  std::vector<Edge> KruskalMST();

private:
  string authorFile_;
  string videoFile_;

  vector<int> nodes_list;

  vector<string> SplitString(string &str1, char sep);
  std::string file_to_string(const std::string &filename);
};

bool compareEdges(Edge edge1, Edge edge2);
