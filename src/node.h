#pragma once
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;
class node {
public:
  int uid;
  double views;
  double likes;
  double coins;
  unordered_map<int, Edge> neighbors; // key: neighbor uid, value: edge
  node(vector<string> input)
      : uid(stoi(input[0])), views(stod(input[1])), likes(stod(input[2])),
        coins(stod(input[3])) {
    /*author exist in authorData.csv, read line by line*/
  }
  node() : uid(0), views(0), likes(0), coins(0) {
    /* author doesn't exist in authorData.csv, use -1 for views,likes
     * and coins.
     */
  }
};