n, s = map(int, input().split())
a = list(map(int, input().split()))
b = list(map(int, input().split()))

color = [[0, 0] for _ in range(n)]
found = False

def dfs(i, dir):
    global found
    color[i][dir] = 1
    if i == s - 1:
        found = True
        return
    if dir == 0:
        for j in range(i, n):
            if a[j] == 1 and color[j][dir] == 0:
                dfs(j, dir)
            if a[j] * b[j] == 1 and color[j][1 - dir] == 0:
                dfs(j, 1 - dir)
    else:
        for j in range(i, -1, -1):
            if b[j] == 1 and color[j][dir] == 0:
                dfs(j, dir)
            if a[j] * b[j] == 1 and color[j][1 - dir] == 0:
                dfs(j, 1 - dir)

if a[0] == 1:
    dfs(0, 0)

if found:
    print("YES")
else:
    print("NO")
