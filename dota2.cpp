#include <iostream>
#include <fstream>
#include <ios>
#include <cstring>
#include <vector>

#define MAX_OFFSET_OVERFLOW_ERR_MSG "Error: MAX_OFFSET OVERFLOW"

using namespace std;
/**
 * @TODO
 * attribuer un id à chaque héros
 * pour chaque ligne du fichier de matchs
 *      remplacer les noms par un id précédemment attribué
 *      écrire la nouvelle ligne dans un fichier de correspondance
 */
class IOHelper {
    private:
        string database;
        fstream dbfs;
        static const unsigned long MAX_OFFSET = 164999;

    public:
        IOHelper() {
            database = "db.bin";
        }
        
        int readByte(const unsigned long offset) {
            int byte;
            clog << "IOHelper::readByte at " << offset << "... ";
            if (offset > MAX_OFFSET) {
                throw string(MAX_OFFSET_OVERFLOW_ERR_MSG);
            }
            dbfs.open(database.c_str(), ios::in | ios::binary);
            if (dbfs.is_open()) {
                dbfs.seekg(offset);
                byte = dbfs.get();
                dbfs.close();
            } else {
                throw string("Fatal error: could not open file");
            }

            clog << "... read byte = " << (int) byte << endl;
            return byte;
        }
        
        /**
         * @TODO implement
         *
         */
        char * readMatch(const unsigned short matchIndex) {
            
        }
        
        void writeByte(const char byte, const unsigned long offset) {
            clog << "IOHelper::writeByte " << (int) byte << " at " << offset << "... ";
            if (offset > MAX_OFFSET) {
                throw string(MAX_OFFSET_OVERFLOW_ERR_MSG);
            }
            dbfs.open(database.c_str(), ios::out | ios::binary);
            if (dbfs.is_open()) {
                dbfs.seekp(offset);
                dbfs << byte;
                dbfs.close();
                clog << "done" << endl;
            } else {
                throw string("Fatal error: could not open file");
            }
        }
        
        void writeMatch(const char * bytes, const unsigned int matchIndex) {
            clog << "IOHelper::writeMatch from " << matchIndex << " to " << matchIndex + 10 << "...";
            if (strlen((char *) bytes) != 11) {
                clog << strlen((char *) bytes);
                throw string("Fatal error: can't write block of data since it's size is not 11");
            }
            if (11 * matchIndex  + 10 >= MAX_OFFSET) {
                throw string(MAX_OFFSET_OVERFLOW_ERR_MSG);
            }
            dbfs.open(database.c_str(), ios::in | ios::out | ios::binary);
            if (dbfs.is_open()) {
                dbfs.seekp(11 * matchIndex);
                dbfs.write(bytes, 11);
                dbfs.close();
                clog << "done" << endl;
            } else {
                throw string("Fatal error: could not open file");
            }
        }
};

int main () {
    /**
     * Example
     * Uncomment next block to see a demo
     */
    /*
    IOHelper * io = new IOHelper;
    const char buffer[11] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 1};
    try {
        io->writeByte(65, 164999);
        io->writeMatch(buffer, 0);
        io->readByte(164999);
    } catch (string msg) {
        cout << msg << endl;
    }
    
    delete io;
    */
    return 0;
}