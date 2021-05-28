#include <iostream>
#include <ctime>
#include <algorithm>
#include <fstream> 
#include "List.h"
#include "BinTree.h"

using namespace std;

vector<string> readFileId()
{
    vector<string> listId;
    string temp;
    ifstream file; 
    file.open("identificationlist.txt"); 
    if (!file)
    {
        cout << "���� �� ������\n\n";
        return listId;
    }
    // ������ ���� �� �����
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

    auto vlist = readFileId();
    sort(vlist.begin(), vlist.end());
    /*for (int i = 0; i < vlist.size(); i++)
    {
        cout << vlist[i];
    }*/

    clock_t start_time = clock();
    PNode list = CreateList(vlist);
    OutList(list);
    clock_t end_time = clock();
    double search_time = (double)(end_time - start_time) / CLOCKS_PER_SEC;
    cout << "����� ���������� ������ :" << search_time << endl;

    for (int i = 0; i < vlist.size(); i++)
    {

    }

	return;
}