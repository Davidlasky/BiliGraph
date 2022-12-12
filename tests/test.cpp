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



  /* TEST_CASE 1 Check file read*/
  // check authorlist read


  cout << "---------Test 1 : Check file read---------" << std::endl;
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








   // TEST 2: correlation videos between two people
  cout << "-------Test 2: Check correlated videos between 2 people-------" << std::endl;
  buildGraph graph("../data/authorData_small.csv", "../data/test_small.csv");
  vector<string> corrVideos = {"BV1AT4y167mt","BV1HF411T7oV","BV1eY411P7kW","BV1XZ4y1y7du","BV1mY4y1H7wp",
                                  "BV1QT4y1e79k","BV1Eu411S78m","BV1uY411x78h","BV1AT4y1d7bC"};
  assert(graph.bGraph.uidToNode[13354765].neighbors[7552204].getVideos() == corrVideos);

  cout << "Correlation videos passed!!" << endl;
  std::string output = "";
  for(unsigned int i = 0; i < corrVideos.size(); i++){
    output += corrVideos.at(i);
    output += ",";
  }

  output.pop_back();
  cout << "Videos are: " << output << std::endl;




  cout << "--------Test 3: Check 1 person's neighbor ----------" << std::endl;
  std::vector<int> temp;
  //std::string output = "";
  auto neighbor_temp = graph.bGraph.uidToNode[454143774].neighbors;
  std::for_each(neighbor_temp.begin(), neighbor_temp.end(), [&temp](const std::map<int, Edge>::value_type&p){
    temp.push_back(p.first);
  });
  std::vector<int> correctVect = {32708543,304578055,1848018,474702359,11870568, 81824112, 19642758, 2200736,
                                  350632501,32708362,147166910,1131457022};
  assert(temp == correctVect);

  std::string output2 = "";
  cout << "Check neighbor passed!" << std::endl;
  for(unsigned int i = 0; i < temp.size(); i++){
    output2 += std::to_string(temp.at(i));
    output2 += ",";
  }

  output2.pop_back();

  cout << "Neighbors of 454143774 are: " << output2 << std::endl;



  cout << "--------Test 4: Check BFS ----------" << std::endl;
  vector<vector<int>> bfs_mapping = graph.BFS();

  //check they(47 uploaders) are all in the same graph
  assert(bfs_mapping.at(0).size() == 47);

  cout << "BFS passed!" << std::endl;



  cout << "--------Test 5: Check MST ----------" << std::endl;
  //MST
  vector<vector<Edge>> kruskal = graph.Kruskal();
  vector<double> weightVect;
  vector<Edge> small = kruskal.at(0);
  for(unsigned int i = 0; i < small.size(); i++){
    vector<double> affect = small.at(i).getAffect();
    double biggest = affect.at(0);
    for (unsigned int i = 1; i < affect.size(); i++) {
      if (affect.at(i) > biggest) {
        biggest = affect.at(i);
      }
    }
    weightVect.push_back(biggest);
  }

  bool smaller = true;
  for(unsigned int x = 0; x < weightVect.size()-1; x++){
    if(weightVect.at(x) > weightVect.at(x+1)){
      smaller = false;
      break;
    }
  }
  
  assert(smaller == true);
  cout << "MST passed!" << std::endl;

  

  cout << "--------Test 6: Check Betweeness Centrality ----------" << std::endl;
  //Betweeness centrality
  vector<int> bigMap = bfs_mapping.at(0);
  map<int, int> centeralness = graph.shortestPath(bigMap);
 
    // Reference variable to help find
    // the entry with the highest value
  pair<int, int> entryWithMaxValue = make_pair(0, 0);
 
  // Iterate in the map to find the required entry
  map<int, int>::iterator currentEntry;
  for (currentEntry = centeralness.begin(); currentEntry != centeralness.end(); ++currentEntry) {
 
      // If this entry's value is more than the max value. Set this entry as the max
      if (currentEntry->second > entryWithMaxValue.second) {
        entryWithMaxValue  = make_pair(currentEntry->first,currentEntry->second);
      }
  }
  assert(entryWithMaxValue == make_pair(19642758, 572));
  cout << "Betweeness Centrality passed!" << std::endl;
  cout << "The most 'social' uploader's UID is: " << entryWithMaxValue.first << std::endl;
  cout << "With " << entryWithMaxValue.second << " videos!" << std::endl;

  std::cout << "----------- Test Finished! Bilibili ( ゜- ゜)つロ Cheers~ ------------- " << std::endl;
}
