from itertools import permutations

unique_permutations = sorted(set(''.join(p) for p in permutations(input())))

print(len(unique_permutations))
for perm in unique_permutations:
    print(perm)
