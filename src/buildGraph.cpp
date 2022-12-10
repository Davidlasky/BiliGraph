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

    // add all nodes to nodes_list
    for (size_t i = 0; i < authors.size(); i++) {
      if (find(nodes_list.begin(), nodes_list.end(), authors[i]) !=
          nodes_list.end()) {
        continue;
      }
      nodes_list.push_back(authors.at(i));
    }

    bGraph.insertEdge(otherInfo, authors);
  }
}

vector<vector<int>> buildGraph::BFS() {
  // for all starting nodes, generate it's corresponding BFS traverse map

  // fill it with all nodes initially
  vector<int> nonVisited;

  map<int, node> graphMap = bGraph.uidToNode;
  for (const auto &myPair : graphMap) {
    nonVisited.push_back(myPair.first);
  }

  vector<vector<int>> maps;

  while (!nonVisited.empty()) {
    int seed = nonVisited.back();
    nonVisited.pop_back();
    maps.push_back(BFS_helper(seed, nonVisited));
  }

  //  tansfer queue to vecotr and return
  return maps;
}

vector<int> buildGraph::BFS_helper(int start, vector<int> &nonVisited) {

  //  initialize BFS
  queue<int> authorQueue; //  queue for BFS
  authorQueue.push(start);

  // map stores: all bfs traversal nodes from that start point
  vector<int> map;
  map.push_back(start);

  while (!authorQueue.empty()) {
    int curr = authorQueue.front();
    auto neighbor = bGraph.uidToNode[curr].neighbors;
    for (auto it = neighbor.begin(); it != neighbor.end(); it++) {
      //  search all neighbours from current node

      int curNeighbor = it->first;
      auto currFind = find(nonVisited.begin(), nonVisited.end(), curNeighbor);
      if (currFind != nonVisited.end()) {
        //  neighbor in nonVisited - neighbor not visited yet

        authorQueue.push(curNeighbor); //  enqueue next node
        nonVisited.erase(currFind);
        map.push_back(curNeighbor);
      }
    }
    authorQueue.pop();
  }

  return map;
}

std::vector<Edge> buildGraph::KruskalMST() {
  // initialize and build the Disjoint Set O(n)
  DisjointSets forest;
  for (int v : nodes_list) {
    forest.addelements(v);
  }

  // initialize, build and sort the priority Queue running time O(mlog(n))
  // implement the priority Queue using a sorted array
  std::vector<Edge> priorityQueue;
  for (Edge edge : bGraph.edges_list) {
    priorityQueue.push_back(edge);
  }
  // sort the priority Queue
  std::sort(priorityQueue.begin(), priorityQueue.end(), compareEdges);

  // initialize the the vector that contains all edges to connect the MST
  // this vector is also the output of the function
  std::vector<Edge> spanningTree;

  // keep removing till number of Edges reaches (n - 1)
  while (spanningTree.size() < nodes_list.size() - 1) {
    Edge edge = priorityQueue.front();
    // removing Edge
    priorityQueue.erase(priorityQueue.begin());
    // retrieve the Vertices by name
    int v1 = (edge.source);
    int v2 = (edge.dest);

    // check if two vertices already belong to the same set (already connected)
    if (forest.find(v1) != forest.find(v2)) {
      // push Edge to output vector if two vertices are not already connected
      spanningTree.push_back(edge);
      // set union of two Vertices
      forest.setunion(forest.find(v1), forest.find(v2));
    }
  }
  // return the vector that contains all edges to connect the MST
  return spanningTree;
}

// the compare function to compare two Edges by weights
bool compareEdges(Edge edge1, Edge edge2) {
  return edge1.getWeight() < edge2.getWeight();
}
