def count_less_equal(x, n):
    count = 0
    for i in range(1, n + 1):
        count += min(x // i, n)
    return count

def find_middle(n):
    left, right = 1, n * n
    while left < right:
        mid = (left + right) // 2
        if count_less_equal(mid, n) < (n * n + 1) // 2:
            left = mid + 1
        else:
            right = mid
    return left

n = int(input().strip())

print(find_middle(n))
