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
void createHash(vector<string> vs);

void main()
{
    setlocale(LC_ALL, "rus");

    auto list = readFileId();
    sort(list.begin(), list.end());

    BinTree* tree = new BinTree(list);
    tree->outTree(tree->_head);
    createHash(list);
	return;
}

void createHash(vector<string> vs)
{
    // ������ ���-�������
    HashTable ht;

    // ��������� � �� ��������� ��������������
    for (int i = 0; i < vs.size(); i++) {
      //  ht.add(Identifier(vs[i]));
    }
    ht.add(Identifier("a"));
    ht.add(Identifier("aa"));
    ht.add(Identifier("if"));
    ht.add(Identifier("fi"));
    // �� ������, ���� ������������� �� ����� ������, ������������ ��� ������
    // ��������������� � ���� try/catch
    try
    {
        // ������� �� ����� ���������� � ��������� ���������������
        std::cout << ht.get(vs[2]).name() << std::endl;
        std::cout << ht.get(vs[4]).name() << std::endl;
        std::cout << ht.get(vs[10]).name() << std::endl;
        std::cout << ht.get("fi").name() << std::endl;
        // ��������� ������, ����� ������������� �� ������ ���� ������
        std::cout << ht.get("hello").name() << std::endl;
    }
    catch (const IDNotFoundException& ex)
    {
        // ���� ������������� �� ������ - �������� �� ����
        std::cerr << ex.what() << std::endl;
    }
}