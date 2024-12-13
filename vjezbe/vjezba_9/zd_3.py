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
        return "NO"

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

n, m = map(int, input().split())  
edges = [tuple(map(int, input().split())) for _ in range(m)] 

print(find_negative_cycle(n, m, edges))
