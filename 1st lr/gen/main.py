from random import sample
from string import ascii_letters, digits

#len_ident = int(input('Длина идентификатора: '))
len_ident = 20
#n = int(input('Количество идентификаторов: '))
n = 50

idts = []

def generate_random_ident(length, file):
    letters_and_digits = ascii_letters + digits
    rand_ident = ''.join(sample(letters_and_digits, length))
    idts.append(rand_ident)
    file.write(rand_ident + '\n')

file = open('identificationlist'+'.txt', 'w')
for i in range(n):
    generate_random_ident(len_ident, file)
file.close()

print('Успешно')
