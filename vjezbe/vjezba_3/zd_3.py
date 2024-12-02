from itertools import chain, combinations

def all_subset_sums(lst):
    return {sum(subset) for subset in chain.from_iterable(combinations(lst, r) for r in range(len(lst) + 1))}

target_sum = int(input(""))
lst = list(map(int, input().split()))

mid = len(lst) // 2
left_part = lst[:mid]
right_part = lst[mid:]

left_sums = all_subset_sums(left_part)
right_sums = all_subset_sums(right_part)

found = False
for s in left_sums:
    if target_sum - s in right_sums:
        found = True
        break

if found:
    print("YES")
else:
    print("-1")
