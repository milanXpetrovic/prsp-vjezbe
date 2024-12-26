# de bruijn
import math

seen = set()
edges = []

def dfs(node, k, A):
    for i in range(k):
        str_ = node + A[i]
        if str_ not in seen:
            seen.add(str_)
            dfs(str_[1:], k, A)
            edges.append(i)

def deBruijn(n, k, A):
    seen.clear()
    edges.clear()
    
    startingNode = A[0] * (n - 1)
    dfs(startingNode, k, A)
    
    S = ""
    l = int(math.pow(k, n))
    for i in range(l):
        S += A[edges[i]]
        
    S += startingNode
    return S

n = int(input())

A = "01"

print(deBruijn(n, 2, A))
