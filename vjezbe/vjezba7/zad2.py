import heapq


def shortest_path_from_city(n, matrix):
    m = len(matrix)
    distances = [float("inf")] * m
    distances[n] = 0  # Udaljenost do početnog grada je 0
    pq = [(0, n)]  # Prioritetni red (udaljenost, grad)

    while pq:
        current_distance, current_city = heapq.heappop(pq)

        if current_distance > distances[current_city]:
            continue

        # Prolaz kroz sve susjede trenutnog grada
        for neighbor in range(m):
            weight = matrix[current_city][neighbor]
            if weight > 0:  # Ako postoji poveznica
                distance = current_distance + weight

                if distance < distances[neighbor]:
                    distances[neighbor] = distance
                    heapq.heappush(pq, (distance, neighbor))

    # Provjera dosegljivosti
    for i in range(m):
        if distances[i] == float("inf"):
            return -1

    return distances


with open("ulaz.txt", "r") as f:
    lines = f.readlines()

n, m = map(int, lines[0].split())
matrix = [list(map(int, line.split())) for line in lines[1:]]
n -= 1
# Izračun najkraćih udaljenosti
result = shortest_path_from_city(n, matrix)

# Ispis
if result == -1:
    print(-1)
else:
    print(" ".join(map(str, result)))
