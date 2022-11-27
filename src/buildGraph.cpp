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
    vector<string> line = SplitString(lines, ',');
    bGraph.insertNode(line);
  }
}

vector<string> buildGraph::SplitString(string &str1, char sep) {
  vector<string> fields;
  std::string str = str1;
  std::string::size_type pos;
  while ((pos = str.find(sep)) != std::string::npos) {
    fields.push_back(str.substr(0, pos));
    str.erase(0, pos + 1);
  }
  fields.push_back(str);
  return fields;
}

void buildGraph::insertVideo() {
  std::ifstream text(videoFile_);
  string lines;
  while (getline(text, lines)) {
    vector<string> wholeline = SplitString(lines, ',');
    vector<string> otherInfo;
    for (unsigned int i = 0; i < wholeline.size() - 1; i++) {
      otherInfo.push_back(wholeline.at(i));
    }

    string authorStr = wholeline.at(4);
    string authorTrim = authorStr.substr(2, authorStr.size() - 1);

    vector<string> authorsStr = SplitString(authorTrim, ';');
    vector<int> authors;
    for (unsigned int i = 0; i < authorsStr.size(); i++) {
      authors.push_back(stoi(authorsStr.at(i)));
    }

    bGraph.insertEdge(otherInfo, authors);
  }
}
