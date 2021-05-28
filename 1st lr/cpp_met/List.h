#pragma once
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class List
{
public:
	List(vector<string> listId);
	void addEnd(string newId);
	string find(string fId);
	string find(int numId);
	void delElement(string dId);

	vector<string> outList();

private:
	string id;
	unique_ptr<List> next;
};

