#pragma once
#include <sstream>
#include <iostream>
#include <iomanip>
#include <string>
#include <vector>

using namespace std;

struct Tree
{
	string id;
	Tree *left;
	Tree* right;
};

typedef Tree* PTree;

class BinTree
{
public:
	PTree _head;

	BinTree(vector<string> listId);
	PTree createNode(string s);
	void addElem(PTree head, string newId);
	bool find(PTree head, string fId);
	void helpBalance(int left, int right);

	void outUseMemory();
	void outTree(PTree head, int i = 0);

 private:	
	int _size;
	vector<int> _idx;
};