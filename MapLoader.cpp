//  MapLoader.cpp
//  Part 2
//  Emilie Mines & Zach Eichler.

#include "MapLoader.hpp"

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <stack>
#include <deque>
#include <list>


using namespace std;


//Gets vector of borders as string from file

vector<string> makeBorderListString(string filename){
    vector<string>borderListString;
    string line;
    ifstream mapfile (filename);
    if (mapfile.is_open())
    {
        while ( getline (mapfile,line)){
            //when it reads "borders", start reading line and store borders in string vector
            if (line.find("[borders]") != string::npos) {
                while(getline (mapfile,line)){
                    borderListString.push_back(line);
                }
            }
        };
        mapfile.close();
    }
    else cout << "File not found";
    return borderListString;
}

//this takes in the vector of strings and converts it to a vector of int vectors by splitting the strings on " "
vector<vector<int>>makeBorderListInt(vector<string> borderList){
    vector<vector<int>> borderListInt;
    for(int j = 0; j < borderList.size(); j++){
        string s = borderList[j];
        string start ="";
        vector<int> test;
        for(int i = 0; i < s.size(); ++i){
            if(s[i]!= ' '){
                if(i == s.size()-1){
                    test.push_back(stoi(start));
                }
                start += s[i];
            }else if(s[i] == ' '){
                test.push_back(stoi(start));
                start = "";
            }
        }
        borderListInt.push_back(test);
    }
    //remove first vector from list as it's just itself
    vector<vector<int>>borderListIntTemp;
    for(int i = 0; i<borderListInt.size(); i++){
        vector<int> temp;
        for(int j = 1; j < borderListInt[i].size();j++){
            temp.push_back(borderListInt[i][j]);
        }
        borderListIntTemp.push_back(temp);
    }
    borderListInt = borderListIntTemp;
    return borderListInt;
}

//gets continents by reading the value after the second " " which corresponds to territory
vector<int> getContinents(string filename){
    
    vector<int>continents;
    string line;
    ifstream mapfile (filename);
    if (mapfile.is_open())
    {
        while ( getline (mapfile,line)){
            if (line.find("[coun") != string::npos || line.find("[terr") != string::npos) {
                while(getline (mapfile,line)){
                    
                    string s = line;
                    string theCont ="";
                    int spaceCount = 0;
                    
                    
                    for(int i = 0; i < s.size()-1;i++){
                        if(s[i] == ' '){
                            spaceCount ++;
    
                            if(spaceCount == 2){
                                i++;
                                while(s[i]!= ' '){
                                    theCont += s[i];
                                    i++;
                                }
                                continents.push_back(stoi(theCont));
                            }
                        }
                    }
                    
                    
                    
                    
                    if(line.length() == 1)
                        break;
                    
                }
            }
        };
        
        mapfile.close();
            
    }
    

    else cout << "File not found";
    
    return continents;
    
}


