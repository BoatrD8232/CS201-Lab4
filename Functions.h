#pragma once
#pragma once
#include <algorithm>
#include <iostream>
#include <fstream>
#include <iomanip>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

struct BBPlayer {
    string playerFirstName;
    string playerLastName;
    int games;
    float efg;
    int trb;
    int ast;
    int stl;
    int blk;
    int tov;
    int pts;
    int age;
    int years;
    string position;
    float effRating;  // This field is not loaded from the file
};
// Takes in input and inserts into a vector
void loadVector(ifstream& in, ofstream& err, vector<BBPlayer>& bbPlayer);


// Makes a team of the best players and prints it.
void printTeam(ofstream& report, vector<BBPlayer>& bbPlayer);


// Prints a vector.
void printVector(ofstream& report, vector<BBPlayer> bbPlayer);
// Sorts a vector starting at start anf ending at end.
void bubbleSort(vector<BBPlayer>& vec, int start, int end);