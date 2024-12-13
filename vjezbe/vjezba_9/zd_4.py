def find_cycle(n, m, flights):
    adj = [[] for _ in range(n + 1)] 
    for a, b in flights:
        adj[a].append(b)

    visited = [0] * (n + 1) 
    parent = [-1] * (n + 1)  
    cycle_start = -1
    cycle_end = -1

    def dfs(v):
        nonlocal cycle_start, cycle_end
        visited[v] = 1  
        for neighbor in adj[v]:
            if visited[neighbor] == 0:  
                parent[neighbor] = v
                if dfs(neighbor):
                    return True
            elif visited[neighbor] == 1:
                cycle_start = neighbor
                cycle_end = v
                return True
        visited[v] = 2  
        return False

    for i in range(1, n + 1):
        if visited[i] == 0:  
            if dfs(i):
                break

    if cycle_start == -1:
        return "IMPOSSIBLE"
    
    cycle = []
    cycle.append(cycle_start)
    v = cycle_end
    while v != cycle_start:
        cycle.append(v)
        v = parent[v]
    cycle.append(cycle_start)
    cycle.reverse()

    return len(cycle), cycle

n, m = map(int, input().split())
flights = [tuple(map(int, input().split())) for _ in range(m)]

result = find_cycle(n, m, flights)

if result == "IMPOSSIBLE":
    print(result)
else:
    print(result[0])
    print(" ".join(map(str, result[1])))
