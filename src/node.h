#pragma once
#include <string>
#include <vector>
using namespace std;
class Node {
public:
  string name;
  double views;
  double likes;
  double coins;
  Node(vector<string> input)
      : name(input[0]), views(stod(input[2])), likes(stod(input[3])),
        coins(stod(input[4])) {
    /*author exist in authorData.csv, read line by line*/
  }
  // Node() : name(""), views(0), likes(0), coins(0) {
  /* author doesn't exist in authorData.csv, use -1 for views,likes and coins.
   */
};