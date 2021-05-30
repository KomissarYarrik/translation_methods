#include "BinTree.h"

BinTree::BinTree(vector<string> listId):
	_head(new Tree)
{
	_size = listId.size();
	if (_size == 0) {
		return;
	}
	helpBalance(0, _size - 1);
	_head->id = listId[_idx[0]];
	_head->left = nullptr;
	_head->right = nullptr;

	for (int i = 1; i < _size; i++) {
		addElem(_head,listId[_idx[i]]);
	}
}

PTree BinTree::createNode(string s)
{
	PTree newNode = new Tree;
	newNode->id = s;
	newNode->left = nullptr;
	newNode->right = nullptr;

	return newNode;
}

void BinTree::addElem(PTree head,string newId)
{
	if (head->id == newId) {
		return;
	}
	if (head->id > newId) {
		if (head->left == nullptr) {
			head->left = createNode(newId);
		}
		else
		{
			addElem(head->left, newId);
		}
	}
	if (head->id < newId) {
		if (head->right == nullptr) {
			head->right = createNode(newId);
		}
		else
		{
			addElem(head->right, newId);
		}
	}
}

bool BinTree::find(PTree head, string findId)
{
	bool temp = false;
	if (head->id == findId) {
		return true;
	}
	if (head->id > findId) {
		if (head->left == nullptr) {
			return false;
		}
		else
		{
			temp = find(head->left, findId);
			if (temp == true)
				return true;
		}
	}
	if (head->id < findId) {
		if (head->right == nullptr) {
			return false;
		}
		else
		{
			temp = find(head->right, findId);
			if (temp == true)
				return true;
		}
	}
	return false;
}


void BinTree::outTree(PTree p, int indent)
{	

	if (p != NULL) {
		if (p->right) {
			outTree(p->right, indent + 4);
		}
		if (indent) {
			std::cout << std::setw(indent) << ' ';
		}
		if (p->right) std::cout << " /\n" << std::setw(indent) << ' ';
		std::cout <<int( p->id[0] )<< "\n ";
		if (p->left) {
			std::cout << std::setw(indent) << ' ' << " \\\n";
			outTree(p->left, indent + 4);
		}
	}
}



void BinTree::helpBalance(int left, int right)
{
	if (left > right) {
		return;
	}
	int i = round((right - left) / 2.0) + left;
	_idx.push_back(i);
	helpBalance(i + 1, right);
	helpBalance(left, i - 1);
}

void BinTree::outUseMemory()
{
	cout << "Количество памяти для бинарного дерева:" << endl;
	cout << "Указатели = " << 64 * _size * 2 << "бит(а)" << endl;
	cout << "Доп-но для создания сбалансированного дерева = " << sizeof _idx + _idx.capacity() * sizeof _idx[0] << "бит(а)" << endl;
}
