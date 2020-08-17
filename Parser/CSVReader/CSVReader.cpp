#include "CSVReader.h"

CSVReader::CSVReader(string filename, string dlm) {
    FileName = filename;
    Delimit = dlm;
}

rawData CSVReader::parseRawTxString(string rawTx) {
    rawData rawDataPair;                // Raw Data Pair -> Data,Parents

    Data data;                          // Contains TxID, Sats, Weight
    Parents parents;                    // TxID(s) of Parents

    // String Variables
    string TxID;                        // TxID of this Transaction String
    string Sats;                        // Value in Satoshis of this Transaction String
    string Weight;                      // Weight of this Transaction String
    string parentString;                // Parent Transactions of this Transaction String

    // Run StringStream on the rawTx Data
    stringstream ss(rawTx);
    // First, get Raw TxID
    getline(ss, TxID, ',');

    // Then, get Sats value
    getline(ss, Sats, ',');

    // Then, get Weight Value
    getline(ss, Weight, ',');

    getline(ss, parentString, ' ');


    parents = {parentString};

    data = {TxID, Sats, Weight};

    // Make a data pair
    rawDataPair = make_pair(data, parents);

    return rawDataPair;
}


ParsedTx CSVReader::getData() {
    ifstream readFile(FileName);

    // Raw Transaction
    string rawTxString;

    rawData dataPair;                   // Pair of above two data points
    ParsedTx rawTxData;                 // Vector with all information

    // Check that the file is open
    if(readFile.is_open()) {

        // make sure that the file is still good
        while(readFile.good()) {
            // Get Raw Transaction String
            getline(readFile, rawTxString);

            // Parse Raw Transaction String
            // Extract data
            dataPair = parseRawTxString(rawTxString);

            // Push to Data Structure
            rawTxData.push_back(dataPair);
        }
    } else {
        cout << "error" << endl;
    }
    readFile.close();

    return rawTxData;
}

void CSVReader::writeToFile(string output, JobOrder order) {
    ofstream outputFile(output);
    for (int i = 0; i < order.size(); i++) {

        string outString = order.at(i).getTxID();
        outputFile << outString + '\n';
    }
}
