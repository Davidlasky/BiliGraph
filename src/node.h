#pragma once
#include <string>
using namespace std;
class Node {
public:
  string name;
  long UID;
  long views;
  long likes;
  long coins;
  Node(string name, long UID, long views, long likes, long coins)
      : name(name), UID(UID), views(views), likes(likes),
        coins(coins) { /* nothing */
  }
  Node() : name(""), UID(0), views(0), likes(0), coins(0) { /* nothing */
  }
};