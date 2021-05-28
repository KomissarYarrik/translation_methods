#pragma once
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class BinTree
{
public:
	BinTree(vector<string> listId);
	void addElem(string newId);
	string find(string fId);
	void delElement(string dId);

	vector<string> outList();

private:
	string id;
	unique_ptr<BinTree> next;
};

