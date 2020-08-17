
#ifndef CSVREADER_H
#define CSVREADER_H

#include "../../Helper/Common.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include "../../Assembler/Assembler.h"

class CSVReader {

private:
    // Filename to Read
    string FileName;

    // Delimiter
    string Delimit;

    rawData parseRawTxString(string rawTx);


public:

    CSVReader(string filename, string dlm);
    ParsedTx getData();
    void writeToFile(string output, JobOrder order);
};


#endif //CSVREADER_H
