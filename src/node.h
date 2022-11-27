#pragma once
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;
class Node {
public:
  int uid;
  double views;
  double likes;
  double coins;
  unordered_map<int, Edge> neighbors; // key: neighbor uid, value: edge
  Node(vector<string> input)
      : uid(stoi(input[0])), views(stod(input[2])), likes(stod(input[3])),
        coins(stod(input[4])) {
    /*author exist in authorData.csv, read line by line*/
  }
  // Node() : name(""), views(0), likes(0), coins(0) {
  /* author doesn't exist in authorData.csv, use -1 for views,likes and coins.
   */
};