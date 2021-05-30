#include <iostream>
#include <ctime>
#include <fstream> 
#include "List.h"

using namespace std;

vector<string> readFileId()
{
    vector<string> listId;
    string temp;
    ifstream file; 
    file.open("identificationlist.txt"); 
    if (!file)
    {
        cout << "File not open!\n\n";
        return listId;
    }
    while(!file.eof())
    {
        file >> temp;
        listId.push_back(temp);
        cout << temp << endl;
    }     
   // cout << "Data = " << (sizeof listId + listId.capacity() * sizeof(char)*listId[0].size())  << "byte\n" <<endl;
    file.close();
    return listId;
}

vector<int> shuffle(int size);

void main()
{
    setlocale(LC_ALL, "rus");

    ofstream resfile;
    resfile.open("res.txt", ios::app);

    auto vlist = readFileId();
    resfile << "---- N = " << vlist.size() << "; len = " << vlist[0].size() << "; ----" << endl;
    resfile << "Data = " << (sizeof vlist + vlist.capacity() * sizeof(char) * vlist[0].size()) << "byte\n" << endl;

    ////--------------------LIST--------------------//
    clock_t start_time = clock();
    PNode list = CreateList(vlist);
    clock_t end_time = clock();
    double search_time = (double)(end_time - start_time) / CLOCKS_PER_SEC;
    //cout << "Create_TimeList = " << search_time << endl;
    resfile << "Create_TimeList = " << search_time << endl;

    auto newidx = shuffle(vlist.size());
    double avg_time = 0;
    for (int i = 0; i < vlist.size(); i++)
    {
        clock_t start_time = clock();
        FindList(list, vlist[newidx[i]]);
        clock_t end_time = clock();
        double search_time = (double)(end_time - start_time) / CLOCKS_PER_SEC;
        avg_time += search_time;
    }
    avg_time /= vlist.size();
    //cout << "AvgTime_FindList = " << avg_time << endl;
    resfile << "AvgTime_FindList = " << avg_time << endl;

    //OutList(list);
    outUseMemory(list, resfile);
    
    //--------------------TREE----------------------//
    start_time = clock();
    BinTree* tree = new BinTree(vlist);
    end_time = clock();
    search_time = (double)(end_time - start_time) / CLOCKS_PER_SEC;
    //cout << "Create_TimeTree = " << search_time << endl;
    resfile << "Create_TimeTree = " << search_time << endl;

    newidx = shuffle(vlist.size());
    avg_time = 0;
    for (int i = 0; i < vlist.size(); i++)
    {
        clock_t start_time = clock();
        tree->find(tree->_head,vlist[newidx[i]]);
        clock_t end_time = clock();
        double search_time = (double)(end_time - start_time) / CLOCKS_PER_SEC;
        avg_time += search_time;
    }
    avg_time /= vlist.size();
    //cout << "AvgTime_FindTree = " << avg_time << endl;
    resfile << "AvgTime_FindTree = " << avg_time << endl;
    //tree->outTree(tree->_head);
    tree->outUseMemory(resfile);

    ////--------------------HASH--------------------//
    start_time = clock();
    HashTable* hash = new HashTable(vlist);
    end_time = clock();
    search_time = (double)(end_time - start_time) / CLOCKS_PER_SEC;
   // cout << "Create_TimeHashTable = " << search_time << endl;
    resfile << "Create_TimeHashTable = " << search_time << endl;

    newidx = shuffle(vlist.size());
    avg_time = 0;
    for (int i = 0; i < vlist.size(); i++)
    {
        clock_t start_time = clock();
        hash->find(vlist[newidx[i]]);
        clock_t end_time = clock();
        double search_time = (double)(end_time - start_time) / CLOCKS_PER_SEC;
        avg_time += search_time;
    }
    avg_time /= vlist.size();
    //cout << "AvgTime_FindHashTable = " << avg_time << endl;
    resfile << "AvgTime_FindHashTable = " << avg_time << endl;
    // hash->outHashTable();
    hash->outUseMemory(resfile);
    resfile.close();

	return;
}

vector<int> shuffle(int size)
{
    vector<int> RandomMix;
    bool alreadyHere;
    for (int i = 0; i < size; )
    {
        alreadyHere = false;
        int NewRandomValue = rand() % size;
        for (int j = 0; j < i; j++)
        {
            if (RandomMix[j] == NewRandomValue)
            {
                alreadyHere = true;
                break;
            }
        }
        if (!alreadyHere)
        {
            RandomMix.push_back(NewRandomValue);
            i++;
        }
    }
    return RandomMix;
}