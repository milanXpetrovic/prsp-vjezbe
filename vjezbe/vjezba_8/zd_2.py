def repair_roads(n, edges):
    edges.sort(key=lambda x: x[2])
    parent = list(range(n + 1))
    rank = [0] * (n + 1)

    def find(node):
        if parent[node] != node:
            parent[node] = find(parent[node])
        return parent[node]

    def union(node1, node2):
        root1 = find(node1)
        root2 = find(node2)
        if root1 != root2:
            if rank[root1] > rank[root2]:
                parent[root2] = root1
            elif rank[root1] < rank[root2]:
                parent[root1] = root2
            else:
                parent[root2] = root1
                rank[root1] += 1

    total_cost = 0
    edges_used = 0

    for a, b, cost in edges:
        if find(a) != find(b):
            union(a, b)
            total_cost += cost
            edges_used += 1

    if edges_used != n - 1:
        return "NEMOGUĆE"
    return total_cost


n, m = 5, 6
edges = [
    (1, 2, 3),
    (2, 3, 5),
    (2, 4, 2),
    (3, 4, 8),
    (5, 1, 7),
    (5, 4, 4),
]

print(repair_roads(n, edges))