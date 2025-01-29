from itertools import combinations
from bisect import bisect_left, bisect_right

def get_subsets_sums(arr):
    sums = []
    n = len(arr)
    for i in range(1 << n):
        s = sum(arr[j] for j in range(n) if i & (1 << j))
        sums.append(s)
    return sums

def meet_in_the_middle(n, x, arr):
    left_half, right_half = arr[:n//2], arr[n//2:]
    left_sums = get_subsets_sums(left_half)
    right_sums = get_subsets_sums(right_half)
    
    right_sums.sort()
    
    count = 0
    for s in left_sums:
        lo = bisect_left(right_sums, x - s)
        hi = bisect_right(right_sums, x - s)
        count += hi - lo
        
    return count

n, x = map(int, input().split())
arr = list(map(int, input().split()))

print(meet_in_the_middle(n, x, arr))
