#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

struct Record{
    int key;
    int value;
};

struct Block{
    int ikey, ivalue;
    vector<Record> myRecords;
};

bool CreateRecordFile(char *cIndexFile, int m, int n) // returns true if success and false if
// failure. m is the number of blocks in the file and n is the number of records in a block
{
    fstream data(cIndexFile ,ios::out);
    if(data.fail())
        return false;
    for(int i = 0; i < m ; i++){
        Block block;
        block.ikey = -1;
        if(i == m-1){ /// last block should have ival = -1
            block.ivalue = -1;
        }
        else{
            block.ivalue = i +1;
        }

        /// writing the ikey and ival of the block
        data.write((char*)&block.ikey,sizeof(block.ikey));
        data.write((char*)&block.ivalue,sizeof(block.ivalue));

        for(int i = 0 ; i < n ; i++){/// fill each block with dummy records
            Record rec;
            rec.key = -1;
            rec.value = -1;

            data.write((char*)&rec.key,sizeof(rec.key));
            data.write((char*)&rec.value,sizeof(rec.value));
        }
    }
    data.close();
    return true;
}

int InsertVal(char *cIndexFile, int iToken, int iKey)// returns index of block in which iToken
//and iKey were stored and -1 if failed, where iKey is the key of the record, and iToken = iVal in the record.
{
    fstream data(cIndexFile, ios::in);
    data.seekg(0);/// seek the beginning of the file
    int headerIkey, headerIval;
    data.read((char*)&headerIkey,sizeof(headerIkey));
    data.read((char*)&headerIval,sizeof(headerIval));


    return 1;
}

int main()
{
    //CreateRecordFile("data.txt", 4, 4);
    InsertVal("data.txt", 4, 4);
    return 0;
}




int GetKey(char *cIndexFile, int iBlock, int iRecord); // get value iKey stored in a given block
// iBlock and given record iRecord – returns -1 if record on block is empty


int GetVal(char *cIndexFile, int iBlock, int iRecord); // get value iVal stored in a given block
//iBlock and given record iRecord – returns -1 if record on block is empty

int GetBlockIndex (char *cIndexFile, int iToken); // get index of block containing iKey = iToken
//and -1 if record does not exist

int GetRecordIndex (char *cIndexFile, int iToken); // get index of record containing iKey = iToken
//and -1 if record does not exist

void DeleteKey (char *cIndexFile, int iToken); // delete record containing value iKey = iToken


int FirstEmptyBlock(char *cIndexFile); // return the index of the first empty block.
