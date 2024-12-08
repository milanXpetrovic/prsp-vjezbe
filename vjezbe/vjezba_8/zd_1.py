def build_roads(n, edges):
    from collections import defaultdict

    graph = defaultdict(list)
    for a, b in edges:
        graph[a].append(b)
        graph[b].append(a)

    visited = [False] * (n + 1)

    def dfs(node, component):
        visited[node] = True
        component.append(node)
        for neighbor in graph[node]:
            if not visited[neighbor]:
                dfs(neighbor, component)

    components = []
    for city in range(1, n + 1):
        if not visited[city]:
            component = []
            dfs(city, component)
            components.append(component)

    new_roads = []
    for i in range(len(components) - 1):
        new_roads.append((components[i][0], components[i + 1][0]))

    return len(new_roads), new_roads


n, m = 4, 2
edges = [(1, 2), (3, 4)]

needed_roads, new_roads = build_roads(n, edges)
print(needed_roads)
for road in new_roads:
    print(*road)