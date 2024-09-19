// CS201L-Lab4-FileIO.cpp : This file contains the 'main' function.  
// NAME: David Boatright
// DATE: 9/18/24
// PROJECT: CS201L-Lab4-FileIO Read a *.csv file and output the best basketball team

#include "Functions.h"

int main()
{
    cout << "My Team is the BEST!!\n";

    ifstream inputFile("playerStatsPro.csv");
    ofstream errorFile("errors.txt");
    ofstream reportFile("report.txt");
    vector<BBPlayer> players;

    loadVector(inputFile, errorFile, players);
    bubbleSort(players, 0, 77);
    bubbleSort(players, 78, 157);
    bubbleSort(players, 158, 231);
    bubbleSort(players, 232, 306);
    bubbleSort(players, 307, 402);
    printTeam(reportFile, players);



    inputFile.close();
    errorFile.close();
    reportFile.close();

    return 0;
}
 
