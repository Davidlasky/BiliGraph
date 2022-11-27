#include "buildGraph.h"
#include "buildHelper.h"

using namespace std;

buildGraph::buildGraph(const string &authorFile, const string &videoFile) {
  authorFile_ = authorFile;
  videoFile_ = videoFile;
  constructGraph();
}

void buildGraph::constructGraph() {
  insertAuthor();
  insertVideo();
}

void buildGraph::insertAuthor() {
  std::ifstream text(authorFile_);
  string lines;
  while (getline(text, lines)) {
    vector<string> line = SplitString(lines);
    bGraph.insertNode(line);
  }
}

vector<string> buildGraph::SplitString(string &str1) {
  vector<string> fields;
  std::string str = str1;
  std::string::size_type pos;
  while ((pos = str.find(",")) != std::string::npos) {
    fields.push_back(str.substr(0, pos));
    str.erase(0, pos + 1);
  }
  fields.push_back(str);
  return fields;
}

void buildGraph::insertVideo() {}