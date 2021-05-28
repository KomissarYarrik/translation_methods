#include <iostream>
#include <algorithm>
#include <fstream> 
#include "List.h"
#include "BinTree.h"
#include "Hash.h"

using namespace std;

vector<string> readFileId()
{
    vector<string> listId;
    string temp;
    ifstream file; 
    file.open("identificationlist.txt"); 
    if (!file)
    {
        cout << "Файл не открыт\n\n";
        return listId;
    }
    // Считка слов из файла
    while(!file.eof())
    {
        file >> temp;
        listId.push_back(temp);
        //cout << temp << endl;
    }     
    return listId;
}
void createHash(vector<string> vs);

void main()
{
    setlocale(LC_ALL, "rus");

    auto list = readFileId();
    sort(list.begin(), list.end());

    BinTree* tree = new BinTree(list);
    tree->outTree(tree->_head);
    createHash(list);
	return;
}

void createHash(vector<string> vs)
{
    // Создаём хэш-таблицу
    HashTable ht;

    // Добавляем в неё различные идентификаторы
    for (int i = 0; i < vs.size(); i++) {
      //  ht.add(Identifier(vs[i]));
    }
    ht.add(Identifier("a"));
    ht.add(Identifier("aa"));
    ht.add(Identifier("if"));
    ht.add(Identifier("fi"));
    // На случай, если идентификатор не будет найден, заворачиваем код поиска
    // идентификаторов в блок try/catch
    try
    {
        // Выводим на экран информацию о различных идентификаторах
        std::cout << ht.get(vs[2]).name() << std::endl;
        std::cout << ht.get(vs[4]).name() << std::endl;
        std::cout << ht.get(vs[10]).name() << std::endl;
        std::cout << ht.get("fi").name() << std::endl;
        // Проверяем случай, когда идентификатор не должен быть найден
        std::cout << ht.get("hello").name() << std::endl;
    }
    catch (const IDNotFoundException& ex)
    {
        // Если идентификатор не найден - сообщаем об этом
        std::cerr << ex.what() << std::endl;
    }
}