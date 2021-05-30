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