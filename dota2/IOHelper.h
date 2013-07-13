#ifndef IO_HELPER_H
#define IO_HELPER_H

#include <iostream>
#include <fstream>
#include <ios>
#include <cstring>
#include <vector>

#define MAX_OFFSET_OVERFLOW_ERR_MSG "Error: MAX_OFFSET OVERFLOW"

class IOHelper {
    private:
        std::string database;
        std::fstream dbfs;
        static const unsigned long MAX_OFFSET = 164999;
    public:
        IOHelper();
        int readByte(const unsigned long offset);
        void readMatch(char *match, const unsigned short matchIndex);
        void writeByte(const char byte, const unsigned long offset);
        void writeMatch(const char * bytes, const unsigned int matchIndex);
};
#endif