#include "Hash.h"

#pragma once
#include <iostream>
#include <string>
#include <list>
#include <algorithm>

Identifier::Identifier(const std::string& name) :
    m_name(name)
{
}

std::string Identifier::name() const
{
    return m_name;
}

bool operator==(const Identifier& left, const Identifier& right)
{
    return left.name() == right.name();
}

size_t hash(const Identifier& id)
{
    // Если имя переменной составляет один символ - возвращается его код,
    // умноженный на два
    if (id.name().length() == 1)
        return 2 * size_t(id.name()[0]);

    // Иначе возвращается сумма кодов первых двух символов
    return size_t(id.name()[0]) + size_t(id.name()[1]);
}

IDNotFoundException::IDNotFoundException(const std::string id_name) :
    m_what(std::string("Identifier \'") + id_name + "\' not found!")
{
}

IDNotFoundException::~IDNotFoundException() throw()
{
}


const char* IDNotFoundException::what() const throw()
{
    return m_what.c_str();
}




// Добавление идентификатора в хэш-таблицу
void HashTable::add(const Identifier& id)
{
    // Добавление идентификатора в список, расположенный в таблице по
    // индексу, вычисленному хэш-функцией (с учётом смещения)
    m_hash_table[hash(id) - min_hash_value].push_back(id);
}

// Поиск идентификатора в таблице по имени
Identifier& HashTable::get(const std::string& id_name)
{
    // Сохраняется ссылка на список, в котором потенциально будет
    // расположен идентификатор (для простоты)
    std::list<Identifier>& line = m_hash_table[hash(id_name) - min_hash_value];

    // Поиск идентификаторы в списке по имени
    std::list<Identifier>::iterator it =
        std::find(line.begin(), line.end(), id_name);

    // Если при поиске были просмотренны все элементы списка,и ни один не
    // подошёл - сообщаем о том, что идентификатор не найден, посредством
    // исключения
    if (it == line.end())
        throw IDNotFoundException(id_name);

    // Если идентификатор найден - возвращаем ссылку на него
    return *it;
}
