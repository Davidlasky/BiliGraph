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
  Edge(long u, long v, string label)
      : source(u), dest(v) { /* nothing */
      labels.push_back(label);
  }

  /**
   * Default constructor.
   */
  Edge() : source(0), dest(0), labels(labels) { /* nothing */
  }

  /**
   * Compares two Edges.
   * operator< is defined so Edges can be sorted with std::sort.
   * @param other - the edge to compare with
   * @return whether the current edge is less than the parameter
   */
  bool operator<(const Edge &other) const { return labels.size() < other.labels.size(); }

  /**
   * Gets edge weight.
   */
  double getWeight() const { return this->labels.size(); }


  /**
   * Compares two edges' source and dest.
   * @param other - the edge to compare with
   */
  bool operator==(Edge &other) const {
    if (this->source != other.source)
      return false;
    if (this->dest != other.dest)
      return false;
    return true;
  }



private:
  //string author;
  //double weight;
  
  //BVID
  vector<string> labels;
};
