#include <iostream>
#include <algorithm>
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
        cout << "���� �� ������\n\n";
        return listId;
    }
    // ������ ���� �� �����
    while(!file.eof())
    {
        file >> temp;
        listId.push_back(temp);
        cout << temp << endl;
    }     
    return listId;
}

void main()
{
    setlocale(LC_ALL, "rus");

    auto list = readFileId();
    sort(list.begin(), list.end());

	return;
}