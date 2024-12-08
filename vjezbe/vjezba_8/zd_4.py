def shortest_routes(n, m, q, roads, queries):
    INF = float('inf')
    dist = [[INF] * n for _ in range(n)]

    for i in range(n):
        dist[i][i] = 0

    for a, b, c in roads:
        a -= 1
        b -= 1
        dist[a][b] = min(dist[a][b], c)
        dist[b][a] = min(dist[b][a], c)

    for k in range(n):
        for i in range(n):
            for j in range(n):
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j])

    results = []
    for a, b in queries:
        a -= 1
        b -= 1
        if dist[a][b] == INF:
            results.append(-1)
        else:
            results.append(dist[a][b])

    return results


import sys
input = sys.stdin.read
data = input().splitlines()

n, m, q = map(int, data[0].split())
roads = []
for i in range(1, m + 1):
    a, b, c = map(int, data[i].split())
    roads.append((a, b, c))

queries = []
for i in range(m + 1, m + q + 1):
    a, b = map(int, data[i].split())
    queries.append((a, b))

results = shortest_routes(n, m, q, roads, queries)

print("\n".join(map(str, results)))


