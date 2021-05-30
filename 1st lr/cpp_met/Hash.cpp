#include "Hash.h"

HashTable::HashTable(vector<string> vs)
{
	size = vs.size();
	for (int k = 0; k < size; k++) htable.push_back(NULL);

	for (int i = 0; i < size; i++)
	{
		auto idx = hash(vs[i]);
		if (htable[idx] == NULL)
		{
			htable[idx] = CreateHead(vs[i]);
		}
		else
		{
			AddLast(htable[idx], CreateNode(vs[i]));
		}
	}
}

int HashTable::hash(string id)
{
	long long key = 0;
	for (int i = 0; i < id.size(); i++)
	{
		key += (int)id[i]*((long long)i+1);
	}
	//cout << key % (size - 1) << endl;
	return key % (size - 1);
}

bool HashTable::find(string id)
{
	auto idx = hash(id);
	return FindList(htable[idx],id);
}

void HashTable::outHashTable()
{
	for (int i = 0; i < size; i++)
	{
		if (htable[i] != NULL)
		{
			cout << "hash = " << i << endl;
			OutList(htable[i]);
			cout << "----------------------" << endl;
		}
	}
}

void HashTable::outUseMemory()
{
	int count = 0;
	for (int i = 0; i < size; i++) 
	{
		PNode temp = htable[i];
		count++;
		while (temp != NULL)
		{
			count++;
			temp = temp->next;
		}
	}

	cout << "Memory HashTable:" << endl;
	cout << "Pointers + vector = " << 8 * 8 * count  + sizeof  htable << " bit\n" << endl;
}