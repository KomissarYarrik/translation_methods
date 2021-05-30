#include "Hash.h"

HashTable::HashTable(vector<string> vs)
{
	_size = vs.size();
	for (int k = 0; k < _size; k++) _htable.push_back(NULL);

	for (int i = 0; i < _size; i++)
	{
		auto idx = hash(vs[i]);
		if (_htable[idx] == NULL)
		{
			_htable[idx] = CreateHead(vs[i]);
		}
		else
		{
			AddLast(_htable[idx], CreateNode(vs[i]));
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
	return key % (_size - 1);
}

bool HashTable::find(string id)
{
	auto idx = hash(id);
	return FindList(_htable[idx],id);
}

void HashTable::outHashTable()
{
	for (int i = 0; i < _size; i++)
	{
		if (_htable[i] != NULL)
		{
			cout << "hash = " << i << endl;
			OutList(_htable[i]);
			cout << "----------------------" << endl;
		}
	}
}