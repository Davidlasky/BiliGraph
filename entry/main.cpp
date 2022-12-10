#include "../src/buildGraph.h"
#include <iostream>
#include <vector>
using namespace std;

int main() {
  buildGraph test("../data/authorData.csv", "../data/testReadVideo.csv");
  vector<int> checkBFS = test.BFS(37090048);
  vector<int> bbb = test.BFS(68559);

  for (int t : checkBFS) {
    cout << t << endl;
  }

  cout << "\n";
  for (int t : bbb) {
    cout << t << endl;
  }
  return 0;
}