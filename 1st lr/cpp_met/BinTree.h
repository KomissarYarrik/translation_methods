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
	BinTree(vector<string> listId);
	PTree createNode(string s);
	void addElem(PTree head, string newId);
	bool find(PTree head, string fId);

	void outTree(PTree head, int i = 0);
	void helpBalance(int left, int right);

private:
	PTree _head;
	int _size;
	vector<int> _idx;
};