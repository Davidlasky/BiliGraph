#include "../src/buildGraph.h"
#include "../src/buildHelper.h"
#include "../src/edge.h"
#include "../src/node.h"
//#include "catch.hpp"

#include <algorithm>
#include <catch2/catch_test_macros.hpp>
#include <iostream>
#include <set>
#include <stdexcept>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

int main() {
  // test build pass
  bool flag = true;
  buildGraph graph("../data/authorData_small.csv", "../data/test_small.csv");

  assert(flag == true);
  cout << "Test passed! Yay!" << endl;
  /* TEST_CASE 1 Check file read*/
  // check authorlist read
  buildGraph checkRead("../data/testreadauthor.csv",
                       "../data/testReadVideo.csv");

  const vector<vector<string>> correct_authorlist = {
      {"25503580", "587875.12", "29151.56", "8583.48", "0.014600856",
       "0.049588015"},
      {"598464467", "1583288.193", "91661.42045", "42437.78409", "0.026803575",
       "0.057893074"}};
  assert(checkRead.author_ckecklist == correct_authorlist);
  cout << "read same author list" << endl;

  // check videolist read
  const vector<vector<string>> correct_videolist = {
      {"BV11a411R71H", "1626267", "149146", "59543",
       "[68559;282994;18149131;349991143]"},
      {"BV11B4y1T78M", "1324434", "54797", "6420",
       "[37090048;163404472;297344797;4628033;474505720;30697825;1168413205]"}};
  assert(checkRead.video_checklist == correct_videolist);
  cout << "read same video list" << endl;
  cout << "read file test pass" << endl;
}

/*
TEST_CASE("ckeck authorlist read", "[weight=5]") {
  buildGraph graph("../data/testreadauthor.csv", "../data/test2.csv");

  const vector<vector<string>> correct_list = {
      {"25503580", "587875.12", "29151.56", "8583.48", "0.014600856",
       "0.049588015"},
      {"598464467", "1583288.193", "91661.42045", "42437.78409", "0.026803575",
       "0.057893074"}};

  REQUIRE(graph.author_ckecklist == correct_list);
}
*/