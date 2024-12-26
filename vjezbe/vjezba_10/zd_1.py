# Planets Queries I

def planets_queries(n, q, teleporters, queries):
    max_k = 31
    up = [[0] * n for _ in range(max_k)]

    for i in range(n):
        up[0][i] = teleporters[i] - 1

    for j in range(1, max_k):
        for i in range(n):
            up[j][i] = up[j - 1][up[j - 1][i]]

    results = []
    for x, k in queries:
        x -= 1
        for i in range(max_k):
            if k & (1 << i):
                x = up[i][x]
        results.append(x + 1)

    return results

n, q = map(int, input().split())
teleporters = list(map(int, input().split()))
queries = [tuple(map(int, input().split())) for _ in range(q)]

answers = planets_queries(n, q, teleporters, queries)
print("\n".join(map(str, answers)))
