graph = []


def dfs(i, j, keep=False):
    global graph, x, y
    stack = [(i, j)]
    while stack:
        a, b = stack.pop()
        if graph[a][b] == "O":
            if keep:
                graph[a][b] = "U"
            else:
                graph[a][b] = "X"
            if a - 1 >= 0:
                stack.append((a - 1, b))
            if a + 1 < x:
                stack.append((a + 1, b))
            if b - 1 >= 0:
                stack.append((a, b - 1))
            if b + 1 < y:
                stack.append((a, b + 1))


x = 0
y = 0
while True:
    row = input()
    if row == "":
        break
    x += 1
    y = len(row.split())
    graph.append(row.split())
for i in range(x):
    if i == 0 or i == x - 1:
        for j in range(y):
            if graph[i][j] == "O":
                dfs(i, j, True)
    else:
        dfs(i, 0, True)
        dfs(i, y - 1, True)
for i in range(x):
    for j in range(y):
        # one island
        if graph[i][j] == "O":
            dfs(i, j)

for i in graph:
    for j in i:
        if j == "U":
            print("O", end=" ")
            continue
        print(j, end=" ")
    print()
