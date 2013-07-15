#include "IOHelper.h"
#include <vector>
#include <iostream>
#include <sstream>
#include <algorithm>
#include <map>

using namespace std;

int main() {
    int currentId = 1;
    map<string, int> heroesNameId;
    map<int, string> heroesIdName;

    ifstream ifs("heroes.txt");

    if (ifs.is_open()) {
        string heroName;
        // assign ids and names for two hashmaps
        while (ifs.good()) {
            getline(ifs, heroName);
            heroesNameId[heroName] = currentId;
            heroesIdName[currentId++] = heroName;
        }
        ifs.close();

        // write db from hashmaps and matches results
        ifs.open("trainingdata.txt");
        if (ifs.is_open()) {

            string match, element;
            vector<string> matchElements;
            char heroId;
            IOHelper * io = new IOHelper;
            int i, matchIndex = 0;
            stringstream ss;
            char * matchBytes = new char[11];

            while (getline(ifs, match)) {
                i = 0;
                ss << match;
                while (getline(ss, element, ',')) {
                    // build match binary data
                    matchBytes[i++] = heroesNameId[element] ?
                        (char)heroesNameId[element] : (char)element[0];
                }
                ss.clear();
                // flush binary data into file
                io->writeMatch(matchBytes, matchIndex++);
            }

            delete matchBytes;
            ifs.close();

            delete io;
        } else {
            cout << "Could not open file trainingdata.txt" << endl;
        }
    } else {
        cout << "Could not open file heroes.txt" << endl;
        return 1;
    }
    /**
     * Example
     * Uncomment next block to see a demo
     */
    /*IOHelper * io = new IOHelper;
    char buffer[11] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 1};
    unsigned short i;
    try {
        io->writeByte(65, 164999);
        io->writeMatch(buffer, 0);
        io->readByte(164999);
        io->readMatch(buffer, 14999);
        for (i = 0; i < 11; i ++) {
            cout << (int) buffer[i] << endl;
        }
    } catch (std::string msg) {
        cout << msg << endl;
    }
    delete io;
    */

    return 0;
}