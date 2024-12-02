from itertools import combinations

k = int(input())
n = input()
l = [int(num) for num in n.split()]

found = False
for i in range(1, len(l) + 1):
    for subset in combinations(l, i):
        if sum(subset) == k:
            print(" ".join(map(str, subset)))
            found = True
            break
    if found:
        break

if not found:
    print("Nema podliste sa zadanim zbrojem.")