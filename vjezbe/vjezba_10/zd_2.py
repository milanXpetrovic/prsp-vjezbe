# Planets Queries II

from sys import setrecursionlimit
from collections import deque

setrecursionlimit(10**6)

def bfs(start, end, t):
    visited = [-1] * len(t)
    queue = deque([(start, 0)])
    visited[start] = 0
    while queue:
        node, steps = queue.popleft()
        if node == end:
            return steps
        next_node = t[node] - 1
        if visited[next_node] == -1:
            visited[next_node] = steps + 1
            queue.append((next_node, steps + 1))
    return -1

n, q = map(int, input().split())
t = list(map(int, input().split()))

for _ in range(q):
    a, b = map(int, input().split())
    print(bfs(a - 1, b - 1, t))
