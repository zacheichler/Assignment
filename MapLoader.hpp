//  MapLoader.hpp
//  Part 2
//  Emilie Mines & Zach Eichler.

#ifndef MapLoader_hpp
#define MapLoader_hpp

#include <stdio.h>
#include <vector>
#include <string>
#include <iostream>
#include <list>
#include "Map.hpp"

using namespace std;


vector<string> makeBorderListString(string filename);
vector<vector<int>>makeBorderListInt(vector<string> borderList);
vector<int> getContinents(string filename);



#endif /* MapLoader_hpp */
