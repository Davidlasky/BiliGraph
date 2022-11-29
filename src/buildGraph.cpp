#include "buildGraph.h"
#include "buildHelper.h"
#include "sstream"

using namespace std;

buildGraph::buildGraph(const string authorFile, const string videoFile) {
  authorFile_ = authorFile;
  videoFile_ = videoFile;
  constructGraph(authorFile, videoFile);
}

std::string buildGraph::file_to_string(const std::string &filename) {
  std::ifstream text(filename);

  std::stringstream strStream;
  if (text.is_open()) {
    strStream << text.rdbuf();
  }
  return strStream.str();
}

void buildGraph::constructGraph(const string &authorFile,
                                const string &videoFile) {
  insertAuthor(authorFile);
  insertVideo(videoFile);
}

void buildGraph::insertAuthor(const string &authorFile) {
  std::string temp = file_to_string(authorFile);
  vector<string> lines = SplitString(temp, '\n');

  for (size_t i = 1; i < lines.size(); i++) {
    vector<string> portion = SplitString(lines[i], ',');
    bGraph.insertNode(portion);
  }
  /*
    while (getline(temp, lines)) {
      vector<string> line = SplitString(lines, ',');
      bGraph.insertNode(line);
    }*/
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
  int a = 1;
  a++;
  return fields;
}

void buildGraph::insertVideo(const string &videoFile) {
  std::string text = file_to_string(videoFile);
  // string lines;
  vector<string> str = SplitString(text, '\n');

  for (size_t i = 1; i < str.size(); i++) {
    vector<string> wholeline = SplitString(str[i], ',');
    vector<string> otherInfo;
    for (unsigned int i = 0; i < wholeline.size() - 1; i++) {
      otherInfo.push_back(wholeline.at(i));
    }
    /*
        while (getline(text, lines)) {
          vector<string> wholeline = SplitString(lines, ',');
          vector<string> otherInfo;
          for (unsigned int i = 0; i < wholeline.size() - 1; i++) {
            otherInfo.push_back(wholeline.at(i));
          }*/

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
