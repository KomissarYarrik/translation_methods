#pragma once
#include <iostream>
#include <string>
#include <list>
#include <algorithm>

// Класс "Идентификатор"
// Поскольку это только пример, то в данном случае является просто обёрткой над
// строкой. В реалиности может содержать много дополнительной информации, такой,
// как тип переменной, признак используемости, уровень вложенности и так далее.
class Identifier
{
public:
    // Задаётся имя переменной при создании
    Identifier(const std::string& name);

public:
    // Получается имя переменной
    std::string name() const;

private:
    std::string m_name;
};

// Необходимо для поиска переменной по имени
bool operator==(const Identifier& left, const Identifier& right);
// Функция, вычисляющая хэш
// Принимает идентификатор, хэш которого надо посчитать
// Возвращает вычисленный хэш
size_t hash(const Identifier& id);

// Класс исключение "Идентификатор не найден"
// Нужен для выдачи сообщения о том, что идентификатор не найден в таблице,
// наружу функции поиска идентификатора
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

// Класс "Хэш-таблица", основанная на методе цепочек
// Метод цепочек заключается в следующем: таблица представляет собой массив
// связных списков фиксированного размера. Вычисленный хэш-функцией хэш является
// индексом в этом массиве списков. Известно, что список по этому индексу будет
// содержать все идентификаторы, для которых функция вернула одинаовый хэш.
// Осталось только найти идентификатор в данном списке и возвратить ссылку на
// него.
class HashTable
{
public:
    // Минимально возможное значение хэша
    static const size_t min_hash_value = int('A') + int('0');
    // Максимально возможное значение хэша
    static const size_t max_hash_value = int('z') + int('z');
    // Размер массива списков - хэш-таблицы
    static const size_t hash_table_size = max_hash_value - min_hash_value;

public:
    // Добавление идентификатора в хэш-таблицу
    void add(const Identifier& id);

    // Поиск идентификатора в таблице по имени
    Identifier& get(const std::string& id_name);

private:
    // Хэш-таблица - массив связных списков идентификаторов
    std::list<Identifier> m_hash_table[hash_table_size];
};