#include "List.h"

PNode CreateNode(string newid)
{
	PNode NewNode = new Node;
	NewNode->id = newid;
	NewNode->next = NULL;
	return NewNode;
}

void AddFirst(PNode& Head, PNode NewNode)
{
	NewNode->next = Head;
	Head = NewNode;
}

void AddAfter(PNode p, PNode NewNode)
{
	NewNode->next = p->next;
	p->next = NewNode;
}

PNode CreateList(vector<string> ids)
{
	PNode Head = NULL;
	for (int i = 0; i < ids.size(); i++)
	{
		AddLast(Head, CreateNode(ids[i]));
	}
	return Head;
}

PNode CreateHead(string s)
{
	PNode Head = NULL;
	AddLast(Head, CreateNode(s));
	return Head;
}

void AddLast(PNode& Head, PNode NewNode)
{
	PNode q = Head;
	if (Head == NULL) {
		AddFirst(Head, NewNode);
		return;
	}
	while (q->next) q = q->next;
	AddAfter(q, NewNode);
}

void OutList(PNode Head)
{
	if (Head == NULL) {
		return;
	}
	cout << Head->id << endl;
	OutList(Head->next);
}

bool FindList(PNode Head, string ids)
{
	while (Head != NULL)
	{
		if (Head->id == ids) return true;
		Head = Head->next;
	}
	return false;
}

void outUseMemory(PNode Head)
{
	int count = 1;
	while (Head != NULL)
	{
		count++;
		Head = Head->next;
	}
	cout << "Memory Node:" << endl;
	cout << "Pointers = " << 8 * 8 * count << " bit\n" << endl;
}

/*void AddAfter(PNode head, PNode NewNode)
{
	while (head->next != NULL)
	{
		head = head->next;
	}
	head->next = NewNode;
}*/

/*void CreateList(vector<string> ids)
{
	PNode head;
	head->id = ids[0];
	head->next = NULL;

	for (int i = 1; i < ids.size(); i++)
	{
		AddAfter(head, CreateNode(ids[i]));
	}
	return head
}*/