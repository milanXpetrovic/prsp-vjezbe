def find_negative_cycle(n, m, edges):
    dist = [float('inf')] * (n + 1)
    dist[1] = 0  
    prev = [-1] * (n + 1)

    # Bellman-Ford 
    for _ in range(n - 1):
        for u, v, w in edges:
            if dist[u] + w < dist[v]:
                dist[v] = dist[u] + w
                prev[v] = u

    cycle_start = -1
    for u, v, w in edges:
        if dist[u] + w < dist[v]:
            cycle_start = v
            break

    if cycle_start == -1:
        return "NE"

    cycle = []
    for _ in range(n):
        cycle_start = prev[cycle_start]

    cycle.append(cycle_start)
    node = prev[cycle_start]
    while node != cycle_start:
        cycle.append(node)
        node = prev[node]
    cycle.append(cycle_start)
    cycle.reverse()

    return f"YES\n{' '.join(map(str, cycle))}"

n, m = 4, 5
edges = [(1, 2, 1), (2, 4, 1), (3, 1, 1), (4, 1, -3), (4, 3, -2)]

print(find_negative_cycle(n, m, edges))
