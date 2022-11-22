/**
 * @file edge.h
 * Definition and (minimal) implementation of an edge class.
 */

#pragma once

#include <limits.h>
#include <string>

using namespace std;
class Edge {
public:
  string source; /**< The source of the edge **/
  string dest;   /**< The destination of the edge **/

  /**
   * Parameter constructor for unweighted graphs.
   * @param u - one vertex the edge is connected to
   * @param v - the other vertex it is connected to
   */
  Edge(string u, string v) : source(u), dest(v), weight(-1.0) { /* nothing */
  }

  /**
   * Parameter constructor for weighted graphs.
   * @param u - one vertex the edge is connected to
   * @param v - the other vertex it is connected to
   * @param w - the weight of the edge
   */
  Edge(string u, string v, double w)
      : source(u), dest(v), weight(w) { /* nothing */
  }

  /**
   * Default constructor.
   */
  Edge() : source(""), dest(""), weight(-1) { /* nothing */
  }

  /**
   * Compares two Edges.
   * operator< is defined so Edges can be sorted with std::sort.
   * @param other - the edge to compare with
   * @return whether the current edge is less than the parameter
   */
  bool operator<(const Edge &other) const { return weight < other.weight; }

  /**
   * Gets edge weight.
   */
  double getWeight() const { return this->weight; }

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
  string author;
  double weight;
};
