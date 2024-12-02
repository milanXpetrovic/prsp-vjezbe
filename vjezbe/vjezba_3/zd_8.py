def earliest_time_to_reach_target(t, sx, sy, ex, ey, wind_directions):
    dx = ex - sx
    dy = ey - sy

    for i in range(t):
        direction = wind_directions[i]
        
        if direction == 'E' and dx > 0:
            dx -= 1
        elif direction == 'W' and dx < 0:
            dx += 1
        elif direction == 'N' and dy > 0:
            dy -= 1
        elif direction == 'S' and dy < 0:
            dy += 1
        
        if dx == 0 and dy == 0:
            return i + 1 
    return -1

t, sx, sy, ex, ey = map(int, input().split())
wind_directions = input().strip()

print(earliest_time_to_reach_target(t, sx, sy, ex, ey, wind_directions))
