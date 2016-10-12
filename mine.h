#include "iostream"
#include "vector"
#include "stdlib.h"
using namespace std;
void buildMineField(vector<vector<bool>>& mines, const double& mineProb);
void displayMineLocations(const vector<vector<bool>>& mines);
void fixCounts(const vector<vector<bool>>& mines, vector<vector<unsigned>>& counts);
void displayMineCounts(const vector<vector<unsigned>>& counts);
