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
  buildGraph(const string authorFile, const string videoFile);
  // call bGraph.insertNode and bGraph.insertEdge
  void constructGraph(const string &authorFile, const string &videoFile);
  void insertAuthor(const string &authorFile);
  void insertVideo(const string &videoFile);


private:
  string authorFile_;
  string videoFile_;
  buildHelper bGraph;
  vector<string> SplitString(string &str1, char sep);
  std::string file_to_string(const std::string& filename);
};