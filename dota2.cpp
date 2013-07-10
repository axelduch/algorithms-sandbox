#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <vector>

using namespace std;

class IOHelper {
    private:
        string filename;

    public:
        IOHelper() {
            filename = "db.bin";
        }
        
        void writeByte(unsigned char byte, unsigned long offset) {
            // open stream write binary
            FILE * fptr = fopen(filename.c_str(), "wb");
            
            // buffer the char for writing
            char buffer[1] = {byte};
            
            // shift pointer to desired offset
            fseek(fptr, 0, offset);
            
            // write buffer
            fwrite(buffer, sizeof(char), sizeof(byte), fptr);
            
            // close file
            fclose(fptr);
            
            // free mem
            fptr = NULL;
        } 
        
        /**
         * @TODO implement
         *
         * */
        int readByte(unsigned long offset) {
            
        }
        
        /**
         * @TODO implement
         *
         * */
        char * readMatch(unsigned long offset) {
            /*
            FILE * fptr = fopen(filename.c_str(), "rb");
            long lSize;
            fseek (fptr, 0, 11);
            lSize = ftell(fptr);
            cout << "lSize: " << lSize << endl;
            char * buffer = (char*) malloc(sizeof(char) * lSize);
            fread(buffer, 1, lSize, fptr);
            fclose(fptr);
            return buffer;
            */
        }
};

// attribuer un id à chaque héros
// pour chaque ligne du fichier de matchs
//  remplacer les noms par un id précédemment attribué
//  écrire la nouvelle ligne dans un fichier de correspondance


int main () {
    /*
    IOHelper * io = new IOHelper;
    for (i = 0; i < 11; i++) {
        cout << "Writing at " << i << ", " << i << endl;
        io->writeByte(i, i);    
    }
    char * buffer = io->readMatch(0);
    cout << (int) buffer[2] << endl;
    delete io;
    */
    return 0;
}