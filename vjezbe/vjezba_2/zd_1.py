n = input()
lista = [int(num) for num in n.split()]

best = 0

for i in range(len(lista)):
    for j in range(i, len(lista)):
        suma = 0
        for k in range(i,j):
            suma += lista[k]
        best=max(suma,best)

for i in range(len(lista)):
    suma = 0
    for j in range(i, len(lista)):
        suma += lista[j]
        best=max(suma,best)

suma = 0
for i in range(len(lista)):
        suma = max(lista[i],suma+lista[i])
        best=max(suma,best)


print(best)