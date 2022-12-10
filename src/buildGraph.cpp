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
    for (size_t i = 0; i < authors.size(); i++) {
      dest_list.push_back(authors[i]);
    }
    bGraph.insertEdge(otherInfo, authors);
  }
}

vector<int> buildGraph::BFS(int start) {
  //  Mark all nodes as not visited
  // vector<bool> visited(7, false); //

  map<int, bool> node_visited;
  for (size_t i = 0; i < dest_list.size(); i++) {
    node_visited.insert({dest_list.at(i), false});
  }

  /*
    for (bool tmp : visited) {
      tmp = false;
    }
  */
  //  initialize BFS
  queue<int> airportQueue;  //  queue for BFS
  queue<int> searchQueue;   //  order of nodes visited during BFS
  airportQueue.push(start); //  enqueue first airport
  searchQueue.push(start);
  int curr = start; //  current node being visited

  //  BFS
  while (!airportQueue.empty()) {
    curr = airportQueue.front();
    for (auto it = bGraph.uidToNode[curr].neighbors.begin();
         it != bGraph.uidToNode[curr].neighbors.end();
         it++) { //  search all neighbours from current node
      if (!node_visited.find(it->first)->second) {
        // if (!visited[it->first]) {      //  next node has not been visited
        searchQueue.push(it->first);  //  add node to BFS search
        airportQueue.push(it->first); //  enqueue next node
        node_visited.find(it->first)->second = true;
        // visited[it->first] = true;
      }
    }
    airportQueue.pop();
  }

  //  tansfer queue to vecotr and return
  vector<int> search;
  while (!searchQueue.empty()) {
    int ap = searchQueue.front();
    search.push_back(ap);
    searchQueue.pop();
  }
  return search;
}
