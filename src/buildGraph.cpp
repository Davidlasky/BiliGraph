#include "buildGraph.h"
#include "buildHelper.h"
#include "sstream"

using namespace std;

buildGraph::buildGraph(const string authorFile, const string videoFile) {
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

  for (unsigned int i = 1; i < lines.size(); i++) {
    // std::cout << "insertAuthor index:" << i << std::endl;
    vector<string> portion = SplitString(lines[i], ',');
    bGraph.insertNode(portion);

    // for test read file of authors
    author_ckecklist.push_back(portion);
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
  return fields;
}

void buildGraph::insertVideo(const string &videoFile) {
  std::string temp = file_to_string(videoFile);
  vector<string> lines = SplitString(temp, '\n');

  for (unsigned int i = 1; i < lines.size(); i++) {
    // std::cout << "insertVideo index: " << i << std::endl;
    vector<string> wholeline = SplitString(lines[i], ',');

    // for test read file of video
    video_checklist.push_back(wholeline);

    vector<string> otherInfo;
    for (unsigned int i = 0; i < wholeline.size() - 1; i++) {
      otherInfo.push_back(wholeline.at(i));
    }

    string authorStr = wholeline.at(4);
    string authorTrim = authorStr.substr(1, authorStr.size() - 3);

    vector<string> authorsStr = SplitString(authorTrim, ';');
    vector<int> authors;
    for (unsigned int i = 0; i < authorsStr.size(); i++) {
      authors.push_back(stoi(authorsStr.at(i)));
    }

    bGraph.insertEdge(otherInfo, authors);
  }
}
