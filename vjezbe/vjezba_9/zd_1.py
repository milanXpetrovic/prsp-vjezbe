# usmjereni graf

from collections import defaultdict

def topological_sort(graph, num_vertices):
    visited = set()
    stack = []

    def dfs(node):
        if node not in visited:
            visited.add(node)
            for neighbor in graph[node]:
                dfs(neighbor)
            stack.append(node)

    for node in graph:
        if node not in visited:
            dfs(node)

    return stack[::-1]


num_vertices = int(input())
edges = []

while True:
    line = input()
    if not line.strip():
        break
    edges.append(line.strip().split())

graph = defaultdict(list)
for edge in edges:
    u, v = edge
    graph[u].append(v)

for u, v in edges:
    if u not in graph:
        graph[u] = []
    if v not in graph:
        graph[v] = []

sorted_order = topological_sort(graph, num_vertices)

print(" ".join(sorted_order))

