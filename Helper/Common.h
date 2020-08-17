
#ifndef COMMON_H
#define COMMON_H

#include <vector>
#include <unordered_map>

using namespace std;

/*
 * Custom Type Name:
 * Contains:
 *  a) Data --> [0]=TxId, [1]=Fee, [3]=Weight
 *  b) Parents --> N # of Parent Txs
 */

using Data = vector<string>;
using Parents = vector<string>;
using rawData = pair<Data, Parents>;
using ParsedTx = vector<rawData>;



#endif //COMMON_H
