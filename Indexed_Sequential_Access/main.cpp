#include <iostream>
#include <vector>

using namespace std;

int m, n;

struct Record{
int key;
int value;
};

struct Block{
int ikey, ivalue;
vector<Record> myRecords;
};

int main()
{


    return 0;
}


bool CreateRecordFile(char *cIndexFile, int m, int n); // returns true if success and false if
// failure. m is the number of blocks in the file and n is the number of records in a block


int InsertVal(char *cIndexFile, int iToken, int iKey);// returns index of block in which iToken
//and iKey were stored and -1 if failed, where iKey is the key of the record, and iToken = iVal in the record.


int GetKey(char *cIndexFile, int iBlock, int iRecord); // get value iKey stored in a given block
// iBlock and given record iRecord � returns -1 if record on block is empty


int GetVal(char *cIndexFile, int iBlock, int iRecord); // get value iVal stored in a given block
//iBlock and given record iRecord � returns -1 if record on block is empty

int GetBlockIndex (char *cIndexFile, int iToken); // get index of block containing iKey = iToken
//and -1 if record does not exist

int GetRecordIndex (char *cIndexFile, int iToken); // get index of record containing iKey = iToken
//and -1 if record does not exist

void DeleteKey (char *cIndexFile, int iToken); // delete record containing value iKey = iToken


int FirstEmptyBlock(char *cIndexFile); // return the index of the first empty block.
