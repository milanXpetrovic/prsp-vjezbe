def hamming_distance(x, y):
    return bin(x ^ y).count('1')

def min_hamming_distance(n, k, bit_strings):
    v = []
    for s in bit_strings:
        v.append(int(s[::-1], 2))
    
    ans = 32
    for i in range(n):
        for j in range(i + 1, n):
            ans = min(ans, hamming_distance(v[i], v[j]))
    
    return ans

n, k = map(int, input().split())
bit_strings = [input().strip() for _ in range(n)]
print(min_hamming_distance(n, k, bit_strings))