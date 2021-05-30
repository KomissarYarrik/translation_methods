#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <fstream> 
#include "List.h"

using namespace std;

class HashTable
{
public:
	HashTable(vector<string> vs);
	int hash(string id);
	bool find(string id);
	void outHashTable();
	void outUseMemory(ofstream& file);

private:
	vector<PNode> htable;
	int size;
};