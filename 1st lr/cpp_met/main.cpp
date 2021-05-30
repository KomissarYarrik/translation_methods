#pragma execution_character_set("utf-8")
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
    return listId;
}



void main()
{
    setlocale(LC_ALL, "rus");

    auto list = readFileId();
    sort(list.begin(), list.end());

    BinTree* tree = new BinTree(list);
    //tree->outTree(tree->_head);
    HashTable* hash = new HashTable(list);
    hash->outHashTable();

	return;
}

