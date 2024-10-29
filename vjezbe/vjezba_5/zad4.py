x, y = map(int, input().split())
graph = []


def bfs(start):
    global graph, x, y
    visited = []
    stack = [start]
    while stack:
        uc = stack.pop()
        if uc not in visited:
            visited.append(uc)
            visited.extend([i for i in graph[uc] if i not in visited])
    return visited[1:]


groups = []
for i in range(x):
    groups.append(0)
    graph.append([])
for i in range(y):
    a, b = map(int, input().split())
    a -= 1
    b -= 1
    graph[a].append(b)
    graph[b].append(a)
for i in range(x):
    f = bfs(i)
    for j in f:
        if groups[i] != 2:
            groups[j] = 2
    if groups[i] != 2:
        groups[i] = 1


for i in groups:
    print(i, end=" ")
