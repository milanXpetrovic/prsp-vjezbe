x, y = map(int, input().split())
graph = []


def dfs(i, j):
    surf = 0
    global graph, x, y
    stack = [(i, j)]
    while stack:
        a, b = stack.pop()
        if graph[a][b] == "1":
            surf += 1
            graph[a][b] = "0"
            if a - 1 >= 0:
                stack.append((a - 1, b))
            if a + 1 < x:
                stack.append((a + 1, b))
            if b - 1 >= 0:
                stack.append((a, b - 1))
            if b + 1 < y:
                stack.append((a, b + 1))
    return surf


for i in range(x):
    graph.append(input().split())
max_surf = 0
for i in range(x):
    for j in range(y):
        # one island
        if graph[i][j] == "1":
            cand = dfs(i, j)
            max_surf = max(max_surf, cand)

print(max_surf)
