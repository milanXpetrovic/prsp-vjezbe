import heapq

def dijkstra(matrix, start, end):
    rows, cols = len(matrix), len(matrix[0])
    directions = [(0, 1), (1, 0), (0, -1), (-1, 0)] 
    distances = [[float('inf')] * cols for _ in range(rows)]
    distances[start[0]][start[1]] = 0
    priority_queue = [(0, start)]

    while priority_queue:
        current_distance, (x, y) = heapq.heappop(priority_queue)

        if (x, y) == end:
            return current_distance

        if current_distance > distances[x][y]:
            continue

        for dx, dy in directions:
            nx, ny = x + dx, y + dy
            if 0 <= nx < rows and 0 <= ny < cols:
                new_distance = current_distance + matrix[nx][ny]
                if new_distance < distances[nx][ny]:
                    distances[nx][ny] = new_distance
                    heapq.heappush(priority_queue, (new_distance, (nx, ny)))

    return float('inf') 




def floyd_warshall(matrix):
    rows, cols = len(matrix), len(matrix[0])
    nodes = rows * cols
    INF = float('inf')

    distances = [[INF] * nodes for _ in range(nodes)]

    def node_id(x, y):
        return x * cols + y

    directions = [(0, 1), (1, 0), (0, -1), (-1, 0)] 
    for x in range(rows):
        for y in range(cols):
            u = node_id(x, y)
            distances[u][u] = 0 
            for dx, dy in directions:
                nx, ny = x + dx, y + dy
                if 0 <= nx < rows and 0 <= ny < cols:
                    v = node_id(nx, ny)
                    distances[u][v] = matrix[nx][ny]

    for k in range(nodes):
        for i in range(nodes):
            for j in range(nodes):
                distances[i][j] = min(distances[i][j], distances[i][k] + distances[k][j])
    return distances




def bellmanFord(V, edges, src):

    dist = [100000000] * V
    dist[src] = 0


    for i in range(V):
        for edge in edges:
            u, v, wt = edge
            if dist[u] != 100000000 and dist[u] + wt < dist[v]:
                if i == V - 1:
                    return [-1]
                
                dist[v] = dist[u] + wt
    return dist



def bellman_ford(matrix, start):
    rows, cols = len(matrix), len(matrix[0])
    nodes = rows * cols
    INF = float('inf')

    distances = [INF] * nodes
    distances[start] = 0

    def node_id(x, y):
        return x * cols + y

    edges = []
    directions = [(0, 1), (1, 0), (0, -1), (-1, 0)] 
    for x in range(rows):
        for y in range(cols):
            u = node_id(x, y)
            for dx, dy in directions:
                nx, ny = x + dx, y + dy
                if 0 <= nx < rows and 0 <= ny < cols:
                    v = node_id(nx, ny)
                    edges.append((u, v, matrix[nx][ny]))

    for _ in range(nodes - 1):
        for u, v, weight in edges:
            if distances[u] + weight < distances[v]:
                distances[v] = distances[u] + weight

    for u, v, weight in edges:
        if distances[u] + weight < distances[v]:
            raise ValueError("Graph contains a negative-weight cycle")

    return distances

n = 3
start = (0,3)
end = (4, 4) 
graph = [[0, 5, 3, 2, 5], [9, 0, 4, 0, 0], [7, 6, 0, 2, 8], [2, 0, 1, 0, 3], [0, 7, 5, 5, 0]]

shortest_path_dijkstra = dijkstra(graph, start, end)
shortest_path_floyd = floyd_warshall(graph)
shortest_path_belman = bellman_ford(graph, 3)
print(f"Djikstra: {shortest_path_dijkstra}")
print(f"Floyd-Warshall: {shortest_path_floyd[3][24]}")
print(f"Bellman-Warshall: {shortest_path_belman[24]}")