#pragma once
#include "buildHelper.h"
#include <cassert>
#include <fstream>
#include <iostream>
#include <map>
#include <set>
#include <string>
#include <utility>
#include <vector>
class buildGraph {
public:
  buildGraph(const string &authorFile, const string &videoFile);
  // call bGraph.insertNode and bGraph.insertEdge
  void constructGraph();
  void insertAuthor();
  void insertVideo();

private:
  string authorFile_;
  string videoFile_;
  buildHelper bGraph;
  vector<string> SplitString(string &str1, char sep);
};