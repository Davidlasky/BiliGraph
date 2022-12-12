/*
 * @file edge.h
 * Definition and (minimal) implementation of an edge class.
 */

#pragma once

#include <limits.h>
#include <string>
#include <vector>

using namespace std;
class Edge {
public:
  // we use uploader's UID as source and destination
  // BVID(video's ID that they cocreated) as label

  int source; /**< The source of the edge **/
  int dest;   /**< The destination of the edge **/

  /**
   * Parameter constructor for weighted graphs.
   * @param u - one vertex the edge is connected to
   * @param v - the other vertex it is connected to
   * @param w - the weight of the edge
   */
  Edge(int u, int v, vector<string> videos_, vector<int> views_,
       vector<int> likes_, vector<int> coins_, vector<double> affects_)
      : source(u), dest(v), videos(videos_), views(views_), likes(likes_),
        coins(coins_), affects(affects_) { /* nothing */
  }

  /**
   * Default constructor.
   */
  Edge()
      : source(0), dest(0), videos(), views(), likes(), coins(), affects() { /* nothing */
  }

  /**
   * Compares two Edges.
   * operator< is defined so Edges can be sorted with std::sort.
   * @param other - the edge to compare with
   * @return whether the current edge is less than the parameter
   */
  bool operator<(const Edge &other) const {
    return videos.size() < other.videos.size();
  }

  /**
   * Gets edge weight.
   */
  pair<double, int> getWeight() const {
    double biggest = affects.at(0);
    int index = 0;
    for(unsigned int i = 1; i < affects.size(); i++){
      if(affects.at(i) > biggest){
        biggest = affects.at(i);
        index = i;
      }
    }

    pair<double, int> out(biggest, index);
    return out;
  }


  /**
   * Compares two edges' source and dest.
   * @param other - the edge to compare with
   */
  bool operator==(Edge &other) const {
    if (this->source != other.source)
      return false;
    if (this->dest != other.dest) {
      return false;
    }
    //?
    for (unsigned int i = 0; i < videos.size(); i++) {
      if (this->videos.at(i) != other.videos.at(i)) {
        return false;
      }
    }

    return true;
  }

  void addVideo(string video){
    videos.push_back(video);
  }

  void addViews(int view){
    views.push_back(view);
  }

  void addLikes(int like){
    likes.push_back(like);
  }

  void addCoins(int coin){
    coins.push_back(coin);
  }

  void addAffect(double affect){
    affects.push_back(affect);
  }

  vector<string> getVideos(){
    return videos;
  }

private:
  // string author;
  double weight;

  // BVID
  vector<string> videos;
  vector<int> views;
  vector<int> likes;
  vector<int> coins;
  vector<double> affects;
};
