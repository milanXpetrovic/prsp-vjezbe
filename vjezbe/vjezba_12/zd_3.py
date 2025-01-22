def manacher(s):
    t = '#' + '#'.join(s) + '#'
    n = len(t)
    p = [0] * n
    c = r = 0

    for i in range(n):
        mirror = 2 * c - i
        if i < r:
            p[i] = min(r - i, p[mirror])
        while i + p[i] + 1 < n and i - p[i] - 1 >= 0 and t[i + p[i] + 1] == t[i - p[i] - 1]:
            p[i] += 1
        if i + p[i] > r:
            c, r = i, i + p[i]
    
    return p

def longest_palindromic_substring(s):
    p = manacher(s)
    max_len = 0
    center = 0

    for i in range(len(p)):
        if p[i] > max_len:
            max_len = p[i]
            center = i

    start = (center - max_len) // 2
    return s[start:start + max_len]

S = input().strip()
print(longest_palindromic_substring(S))
