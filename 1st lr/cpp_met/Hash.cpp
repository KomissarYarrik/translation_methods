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
    // ���� ��� ���������� ���������� ���� ������ - ������������ ��� ���,
    // ���������� �� ���
    if (id.name().length() == 1)
        return 2 * size_t(id.name()[0]);

    // ����� ������������ ����� ����� ������ ���� ��������
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




// ���������� �������������� � ���-�������
void HashTable::add(const Identifier& id)
{
    // ���������� �������������� � ������, ������������� � ������� ��
    // �������, ������������ ���-�������� (� ������ ��������)
    m_hash_table[hash(id) - min_hash_value].push_back(id);
}

// ����� �������������� � ������� �� �����
Identifier& HashTable::get(const std::string& id_name)
{
    // ����������� ������ �� ������, � ������� ������������ �����
    // ���������� ������������� (��� ��������)
    std::list<Identifier>& line = m_hash_table[hash(id_name) - min_hash_value];

    // ����� �������������� � ������ �� �����
    std::list<Identifier>::iterator it =
        std::find(line.begin(), line.end(), id_name);

    // ���� ��� ������ ���� ������������ ��� �������� ������,� �� ���� ��
    // ������� - �������� � ���, ��� ������������� �� ������, �����������
    // ����������
    if (it == line.end())
        throw IDNotFoundException(id_name);

    // ���� ������������� ������ - ���������� ������ �� ����
    return *it;
}
