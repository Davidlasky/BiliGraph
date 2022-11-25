/**
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
  //we use uploader's UID as source and destination
  //BVID(video's ID that they cocreated) as label

  long source; /**< The source of the edge **/
  long dest;   /**< The destination of the edge **/



  /**
   * Parameter constructor for weighted graphs.
   * @param u - one vertex the edge is connected to
   * @param v - the other vertex it is connected to
   * @param w - the weight of the edge
   */
  Edge(long u, long v, string video, long view, long like, long coin)
      : source(u), dest(v) { /* nothing */
      videos.push_back(video);
      views.push_back(view);
      likes.push_back(like);
      coins.push_back(coin);
  }

  /**
   * Default constructor.
   */
  Edge() : source(0), dest(0), videos(), views(), likes(), coins() { /* nothing */
  }

  /**
   * Compares two Edges.
   * operator< is defined so Edges can be sorted with std::sort.
   * @param other - the edge to compare with
   * @return whether the current edge is less than the parameter
   */
  bool operator<(const Edge &other) const { return videos.size() < other.videos.size(); }

  /**
   * Gets edge weight.
   */
  double getWeight() const { return this->videos.size(); }


  /**
   * Compares two edges' source and dest.
   * @param other - the edge to compare with
   */
  bool operator==(Edge &other) const {
    if (this->source != other.source)
      return false;
    if (this->dest != other.dest){
      return false;
    }
    //?
    for(unsigned int i = 0; i < videos.size(); i++){
      if(this->videos.at(i) != other.videos.at(i)){
        return false;
      }
    }

    return true;
  }



private:
  //string author;
  //double weight;

  //BVID
  vector<string> videos;
  vector<long> views;
  vector<long> likes;
  vector<long> coins;

};
