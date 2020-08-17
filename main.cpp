
#include "Helper/Common.h"
#include "Parser/CSVReader/CSVReader.h"
#include "Assembler/Assembler.h"

using namespace std;

int main() {

    // Open File and Parse
    CSVReader reader("../Output/mempool.csv", ",");
    ParsedTx rawTxs = reader.getData();

    // Assemble Transaction Objects and Priority Queue
    Assembler processor(rawTxs);

    // Sort into Appropriate Job Order
    JobOrder order = processor.schedule();

    // Write to file
    reader.writeToFile("../Output/block.txt", order);

}

