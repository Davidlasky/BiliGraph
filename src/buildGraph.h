#pragma once
#include "buildHelper.h"
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
  vector<int> BFS(int start);

private:
  string authorFile_;
  string videoFile_;

  vector<string> SplitString(string &str1, char sep);
  std::string file_to_string(const std::string &filename);
};