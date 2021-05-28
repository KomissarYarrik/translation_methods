#pragma once
#include <iostream>
#include <string>
#include <list>
#include <algorithm>

// ����� "�������������"
// ��������� ��� ������ ������, �� � ������ ������ �������� ������ ������� ���
// �������. � ���������� ����� ��������� ����� �������������� ����������, �����,
// ��� ��� ����������, ������� ��������������, ������� ����������� � ��� �����.
class Identifier
{
public:
    // ������� ��� ���������� ��� ��������
    Identifier(const std::string& name);

public:
    // ���������� ��� ����������
    std::string name() const;

private:
    std::string m_name;
};

// ���������� ��� ������ ���������� �� �����
bool operator==(const Identifier& left, const Identifier& right);
// �������, ����������� ���
// ��������� �������������, ��� �������� ���� ���������
// ���������� ����������� ���
size_t hash(const Identifier& id);

// ����� ���������� "������������� �� ������"
// ����� ��� ������ ��������� � ���, ��� ������������� �� ������ � �������,
// ������ ������� ������ ��������������
class IDNotFoundException : std::exception
{
public:
    IDNotFoundException(const std::string id_name);

    virtual ~IDNotFoundException() throw();

public:
    const char* what() const throw();

private:
    std::string m_what;
};

// ����� "���-�������", ���������� �� ������ �������
// ����� ������� ����������� � ���������: ������� ������������ ����� ������
// ������� ������� �������������� �������. ����������� ���-�������� ��� ��������
// �������� � ���� ������� �������. ��������, ��� ������ �� ����� ������� �����
// ��������� ��� ��������������, ��� ������� ������� ������� ��������� ���.
// �������� ������ ����� ������������� � ������ ������ � ���������� ������ ��
// ����.
class HashTable
{
public:
    // ���������� ��������� �������� ����
    static const size_t min_hash_value = int('A') + int('0');
    // ����������� ��������� �������� ����
    static const size_t max_hash_value = int('z') + int('z');
    // ������ ������� ������� - ���-�������
    static const size_t hash_table_size = max_hash_value - min_hash_value;

public:
    // ���������� �������������� � ���-�������
    void add(const Identifier& id);

    // ����� �������������� � ������� �� �����
    Identifier& get(const std::string& id_name);

private:
    // ���-������� - ������ ������� ������� ���������������
    std::list<Identifier> m_hash_table[hash_table_size];
};