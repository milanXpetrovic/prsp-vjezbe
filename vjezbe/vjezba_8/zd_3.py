import heapq
import sys

def shortest_routes(n, m, edges):
    # Graf predstavljamo kao listu susjedstva
    graph = [[] for _ in range(n + 1)]
    for a, b, c in edges:
        graph[a].append((b, c))

    # Dijkstra's algoritam
    distances = [float('inf')] * (n + 1)
    distances[1] = 0
    pq = [(0, 1)]  # (udaljenost, čvor)

    while pq:
        current_distance, current_node = heapq.heappop(pq)

        if current_distance > distances[current_node]:
            continue

        for neighbor, weight in graph[current_node]:
            distance = current_distance + weight
            if distance < distances[neighbor]:
                distances[neighbor] = distance
                heapq.heappush(pq, (distance, neighbor))

    return distances[1:]  # Vraćamo udaljenosti za gradove 1 do n



input = sys.stdin.read
data = input().splitlines()
n, m = map(int, data[0].split())
edges = []
for line in data[1:]:
    a, b, c = map(int, line.split())
    edges.append((a, b, c))

# Izračunaj najkraće udaljenosti
result = shortest_routes(n, m, edges)
print(" ".join(map(str, result)))


