#include "Functions.h"

bool isDigits(string str) {
    return str.find_first_not_of("0123456789.") == string::npos;
}

void loadVector(ifstream& in, ofstream& err, vector<BBPlayer>& bbPlayer) {
    string line, csVal, errorPlace;
    getline(in, line);
    while (getline(in, line)) {
        stringstream inVals(line);
        BBPlayer tempPlayer; 
        getline(inVals, csVal, ',');
        tempPlayer.playerFirstName = csVal;
        getline(inVals, csVal, ',');
        tempPlayer.playerLastName = csVal;
        try {
            getline(inVals, csVal, ',');
            try {
                tempPlayer.games = stoi(csVal);
                if (tempPlayer.games < 20) {
                    throw out_of_range("less that 20 games");
                }
            }
            catch (...) {
                err << "Error found in player " << tempPlayer.playerFirstName << " " << tempPlayer.playerLastName << " in value: games" << endl;
                continue;
            }
            try {
                getline(inVals, csVal, ',');
                tempPlayer.efg = stof(csVal);
            }
            catch (...) {
                err << "Error found in player " << tempPlayer.playerFirstName << " " << tempPlayer.playerLastName << " in value: efg" << endl;
                continue;
            }
            try {
                getline(inVals, csVal, ',');
                tempPlayer.trb = stoi(csVal);
            }
            catch (...) {
                err << "Error found in player " << tempPlayer.playerFirstName << " " << tempPlayer.playerLastName <<" in value: trb" << endl;
                continue;
            }
            try {
                getline(inVals, csVal, ',');
                tempPlayer.ast = stoi(csVal);
            }
            catch (...) {
                err << "Error found in player " << tempPlayer.playerFirstName << " " << tempPlayer.playerLastName << " in value: ast" << endl;
                continue;
            }
            try {
                getline(inVals, csVal, ',');
                tempPlayer.stl = stoi(csVal);
            }
            catch (...) {
                err << "Error found in player " << tempPlayer.playerFirstName << " " << tempPlayer.playerLastName << " in value: stl" << endl;
                continue;
            }
            try {
                getline(inVals, csVal, ',');
                tempPlayer.blk = stoi(csVal);
            }
            catch (...) {
                err << "Error found in player " << tempPlayer.playerFirstName << " " << tempPlayer.playerLastName << " in value: blk" << endl;
                continue;
            }
            try {
                getline(inVals, csVal, ',');
                tempPlayer.tov = stoi(csVal);
            }
            catch (...) {
                err << "Error found in player " << tempPlayer.playerFirstName << " " << tempPlayer.playerLastName << " in value: tov" << endl;
                continue;
            }
            try {
                getline(inVals, csVal, ',');
                tempPlayer.pts = stoi(csVal);
            }
            catch (...) {
                err << "Error found in player " << tempPlayer.playerFirstName << " " << tempPlayer.playerLastName << " in value: pts" << endl;
                continue;
            }
            try {
                getline(inVals, csVal, ',');
                tempPlayer.age = stoi(csVal);
            }
            catch (...) {
                err << "Error found in player " << tempPlayer.playerFirstName << " " << tempPlayer.playerLastName << " in value: age" << endl;
                continue;
            }
            try {
                getline(inVals, csVal, ',');
                tempPlayer.years = stoi(csVal);
                if (tempPlayer.years < 0) {
                    throw out_of_range("bad year");
                }
            }
            catch (...) {
                err << "Error found in player " << tempPlayer.playerFirstName << " " << tempPlayer.playerLastName << " in value: years" << endl;
                continue;
            }
        }
        catch (...) {
            err << "Error found in player " << tempPlayer.playerFirstName << " " << tempPlayer.playerLastName << endl;
            continue;
        }
        getline(inVals, csVal, ',');
        tempPlayer.position = csVal;
        tempPlayer.effRating = (tempPlayer.pts + tempPlayer.trb + tempPlayer.ast + tempPlayer.stl + tempPlayer.blk - (tempPlayer.pts / (tempPlayer.efg) - tempPlayer.pts + tempPlayer.tov)) / tempPlayer.games;
        bbPlayer.push_back(tempPlayer);
    }
}

void printTeam(ofstream& report, vector<BBPlayer>& bbPlayer) {
    vector<BBPlayer> team;
    team.push_back(bbPlayer[76]);
    team.push_back(bbPlayer[77]);
    team.push_back(bbPlayer[155]);
    team.push_back(bbPlayer[156]);
    team.push_back(bbPlayer[157]);
    team.push_back(bbPlayer[229]);
    team.push_back(bbPlayer[230]);
    team.push_back(bbPlayer[231]);
    team.push_back(bbPlayer[304]);
    team.push_back(bbPlayer[305]);
    team.push_back(bbPlayer[306]);
    team.push_back(bbPlayer[400]);
    team.push_back(bbPlayer[401]);
    team.push_back(bbPlayer[402]);
    for (int i = 0; i < team.size(); ++i) {
        report << team[i].playerFirstName << " " << team[i].position << " " << team[i].effRating << endl;
    }
}

void printVector(ofstream& report, vector<BBPlayer> players) {
    int c = 0, pf = 0, pg = 0, sf = 0, sg = 0;
    for (int i = 0; i < players.size(); ++i) {
        cout << players[i].playerFirstName << " " << players[i].position << " " << players[i].effRating << endl;
    }
}
// Code taken from chat gpt.
void bubbleSort(vector<BBPlayer>& vec, int start, int end) {
    for (int i = start; i < end; ++i) {
        bool changeMade = false; // Reset the flag for each outer loop iteration
        for (int j = start; j < end - (i - start); ++j) { // Adjust the end of the inner loop
            if (vec[j].effRating > vec[j + 1].effRating) {
                std::swap(vec[j], vec[j + 1]); // Use std::swap for cleaner code
                changeMade = true; // A swap was made
            }
        }
        // If no changes were made, the vector is sorted
        if (!changeMade) {
            break; // Exit early if the list is already sorted
        }
    }
}