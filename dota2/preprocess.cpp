#include <algorithm>
#include <fstream>
#include "IOHelper.h"
#include <iostream>
#include <map>
#include <string>
#include <vector>

using namespace std;

int main () {
    map<char, string> heroesIdName;
    // vector<char> => [0]: gameCount, [1]: winCount
    map<unsigned short, vector<unsigned char> > heroesPairs;

    char * gameBuffer = new char[11];
    unsigned char bigId, tinyId, currentId = 1;;

    unsigned short
        h1,
        h2,
        hash;

    unsigned int matchIndex;

    IOHelper *io = new IOHelper;
    ifstream ifs("heroes.txt");
    ofstream ofs("preprocess.log", ios::out);

    if (ifs.is_open()) {
        string heroName;
        // assign ids and names for two hashmaps
        while (ifs.good()) {
            getline(ifs, heroName);
            heroesIdName[currentId++] = heroName;
        }
        ifs.close();
    }

    for (matchIndex = 0; matchIndex < 15000; matchIndex++) {
        // get match
        io->readMatch(gameBuffer, matchIndex);
        for (h1 = 0; h1 < 9; h1++) {
            for (h2 = h1 + 1; h2 < 10; h2++) {
                // calculate lowest id
                tinyId = min(gameBuffer[h1], gameBuffer[h2]);
                // calculate highest id
                bigId = tinyId == gameBuffer[h2] ?
                    gameBuffer[h1] : gameBuffer[h2];
                // if they were in the same team !
                if ((h1 < 5) * (h2 < 5) || (h1 > 4) * (h2 > 4)) {
                    // packing ids so that we can remember they were teammates
                    hash = bigId << 8 | tinyId;
                    // increment gameCount
                    if (!heroesPairs.count(hash)) {
                        heroesPairs[hash].push_back(0);
                        heroesPairs[hash].push_back(0);
                    }
                    heroesPairs[hash][0] = heroesPairs[hash][0] + 1;
                    if (h1 < 5) { // if they were in team 1
                        heroesPairs[hash][1] += ((int)gameBuffer[10] == 1);
                    } else { // they were in team 2
                        heroesPairs[hash][1] += ((int)gameBuffer[10] == 2);
                    }
                    //ofs << hash << ": gameCount => " << (int)heroesPairs[hash][0] << ", winCount => " << (int)heroesPairs[hash][1] << endl;
                } else { // they were in opposite teams
                    // packing ids so that we can remember they were opponents
                    hash = tinyId << 8 | bigId;
                }
            }
        }
    }

    // dump heroesPairs to see what it looks like

    delete io;
    delete gameBuffer;

    return 0;
}