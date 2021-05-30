#include <iostream>
#include <algorithm>
#include <fstream> 

#include "List.h"
#include "BinTree.h"
#include "Hash.h"

using namespace std;

vector<string> readFileId()
{
    vector<string> listId;
    string temp;
    ifstream file; 
    file.open("identificationlist.txt"); 
    if (!file)
    {
        cout << "‘айл не открыт\n\n";
        return listId;
    }
    // —читка слов из файла
    while(!file.eof())
    {
        file >> temp;
        listId.push_back(temp);
        //cout << temp << endl;
    }     
    cout << "Data = " << (sizeof listId + listId.capacity() * sizeof(char)*listId[0].size()) * 8 << " bit\n" <<endl;
    return listId;
}

void main()
{
    setlocale(LC_ALL, "rus");

    auto vlist = readFileId();
    sort(vlist.begin(), vlist.end());

    //LIST//
    PNode list = CreateList(vlist);
    outUseMemory(list);

    //TREE//
    BinTree* tree = new BinTree(vlist);
    //tree->outTree(tree->_head);
    tree->outUseMemory();

    //HASH
    HashTable* hash = new HashTable(vlist);
   // hash->outHashTable();
    hash->outUseMemory();

	return;
}

