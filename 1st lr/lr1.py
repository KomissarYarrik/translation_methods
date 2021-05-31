from random import sample
from string import ascii_letters, digits
from subprocess import call
from os import remove
import matplotlib.pyplot as plt
import time

def generate_random_ident(length, file):
    letters_and_digits = ascii_letters + digits
    rand_ident = ''.join(sample(letters_and_digits, length))
    idts.append(rand_ident)
    file.write(rand_ident + '\n')

try:
    remove('res.txt')
except OSError:
    pass

len_ident = int(input('Длина идентификатора: '))
#len_ident = 20
n = int(input('Количество идентификаторов: '))
#n = 50

idts = []

file = open('identificationlist'+'.txt', 'w')
for i in range(n):
    generate_random_ident(len_ident, file)
file.close()

print('Успешно создан список идентификаторов')

Create_TimeList, AvgTime_FindList, Memory_Node = [],[],[]
Create_TimeTree, AvgTime_FindTree, Memory_BinTree = [],[],[]
Create_TimeHashTable, AvgTime_FindHashTable, Memory_HashTable = [],[],[]
exp_number = []

experiment = int(input('Количество экспериментов: '))
exp_start = time.time()
print('Начало эксперимента: ', time.ctime(exp_start))
for i in range(experiment):
    print('Эксперимент №',i+1, time.ctime(time.time()))
    call('Lab_1.exe')
    exp_number.append(i+1)

res = open('res'+'.txt', 'r')
for line in res:
    #скорость
    if 'Create_TimeList = ' in line:
        Create_TimeList.append(float(line[17:(len(line)-1)]))
    if 'Create_TimeTree = ' in line:
        Create_TimeTree.append(float(line[17:(len(line)-1)]))
    if 'Create_TimeHashTable = ' in line:
        Create_TimeHashTable.append(float(line[22:(len(line)-1)]))
    #поиск
    if 'AvgTime_FindList = ' in line:
        AvgTime_FindList.append(float(line[18:(len(line)-1)]))
    if 'AvgTime_FindTree = ' in line:
        AvgTime_FindTree.append(float(line[18:(len(line)-1)]))
    if 'AvgTime_FindHashTable = ' in line:
        AvgTime_FindHashTable.append(float(line[23:(len(line)-1)]))
    #память
    if 'Memory Node:Pointers = ' in line:
        Memory_Node.append(float(line[22:(len(line)-1)]))
    if 'Memory_BinTree:Pointers = ' in line:
        Memory_BinTree.append(float(line[25:(len(line)-1)]))
    if 'Memory_HashTable:Pointers_+_vector = ' in line:
        Memory_HashTable.append(float(line[36:(len(line)-1)]))
res.close

exp_end = time.time()
exp_time = exp_end - exp_start
print('Конец эксперимента: ', time.ctime(exp_end))
print('Время эксперимента: ', round(exp_time/60, 2), 'сек.')

plt.title('Время создания структуры')
plt.xlabel("Номер эксперимента")
plt.ylabel("Скорость, сек")
plt.plot(exp_number,Create_TimeList,label='Неупорядоченный односвязный список')
plt.plot(exp_number,Create_TimeTree,label='Бинарное дерево поиска')
plt.plot(exp_number,Create_TimeHashTable,label='Хэш-таблица (метод цепочек)')
plt.legend()
plt.show()

plt.title('Среднее время поиска')
plt.xlabel("Номер эксперимента")
plt.ylabel("Скорость, сек")
plt.plot(exp_number,AvgTime_FindList,label='Неупорядоченный односвязный список')
plt.plot(exp_number,AvgTime_FindTree,label='Бинарное дерево поиска')
plt.plot(exp_number,AvgTime_FindHashTable,label='Хэш-таблица (метод цепочек)')
plt.legend()
plt.show()

plt.title('Объем памяти, занимаемый таблицей')
plt.xlabel("Номер эксперимента")
plt.ylabel("байт")
plt.plot(exp_number,Memory_Node,label='Неупорядоченный односвязный список')
plt.plot(exp_number,Memory_BinTree,label='Бинарное дерево поиска')
plt.plot(exp_number,Memory_HashTable,label='Хэш-таблица (метод цепочек)')
plt.legend()
plt.show()
