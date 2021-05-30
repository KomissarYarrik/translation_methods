#pragma once
#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct Node
{
	string id;
	Node* next;
};

typedef Node* PNode;

PNode CreateNode(string newid);

void AddFirst(PNode& Head, PNode NewNode);

void AddAfter(PNode p, PNode NewNode);

PNode CreateList(vector<string> ids);

PNode CreateHead(string ids);

void AddLast(PNode& Head, PNode NewNode);

void OutList(PNode Head);

bool FindList(PNode Head, string ids);

void outUseMemory(PNode Head);

/*void addEndList(string newId);
string FindList(string fId);
string FindList(int numId);
void delElementList(string dId);

vector<string> outList();*/
