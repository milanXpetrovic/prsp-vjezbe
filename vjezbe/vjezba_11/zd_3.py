# grundys game
def mex(v):
    s = set(v)
    for i in range(1000006):
        if i not in s:
            return i

def solve():
    t = int(input())
    
    dp = [0, 0, 0]
    
    for i in range(3, 2000):
        v = []
        for j in range(1, i):
            if i - j > j:
                v.append(dp[j] ^ dp[i - j])
        dp.append(mex(v))
    
    for _ in range(t):
        n = int(input())
        if n >= 2000:
            print("first")
        else:
            print("first" if dp[n] > 0 else "second")



solve()
