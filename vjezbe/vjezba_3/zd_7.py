DIR_LEN = 4
dr = [-1, 0, 1, 0] 
dc = [0, 1, 0, -1] 
PATH_LEN = 48  
GRID_SIZE = 9  
onPath = [[False] * GRID_SIZE for _ in range(GRID_SIZE)]  


def try_path(path_idx, cur_r, cur_c, p):
    if (onPath[cur_r][cur_c - 1] and onPath[cur_r][cur_c + 1] and
        not onPath[cur_r - 1][cur_c] and not onPath[cur_r + 1][cur_c]):
        return 0
    if (onPath[cur_r - 1][cur_c] and onPath[cur_r + 1][cur_c] and
        not onPath[cur_r][cur_c - 1] and not onPath[cur_r][cur_c + 1]):
        return 0

    if cur_r == 7 and cur_c == 1:  
        return 1 if path_idx == PATH_LEN else 0

    if path_idx == PATH_LEN:  
        return 0

    onPath[cur_r][cur_c] = True
    ret = 0

    if p[path_idx] < 4:
        nxt_r = cur_r + dr[p[path_idx]]
        nxt_c = cur_c + dc[p[path_idx]]
        if not onPath[nxt_r][nxt_c]:
            ret += try_path(path_idx + 1, nxt_r, nxt_c, p)
    else:  
        for i in range(DIR_LEN):
            nxt_r = cur_r + dr[i]
            nxt_c = cur_c + dc[i]
            if not onPath[nxt_r][nxt_c]:
                ret += try_path(path_idx + 1, nxt_r, nxt_c, p)

    onPath[cur_r][cur_c] = False
    return ret

line = input().strip()

p = []
for i in range(PATH_LEN):
    cur = line[i]
    if cur == 'U':
        p.append(0)
    elif cur == 'R':
        p.append(1)
    elif cur == 'D':
        p.append(2)
    elif cur == 'L':
        p.append(3)
    else:
        p.append(4)  

for i in range(GRID_SIZE):
    onPath[0][i] = True
    onPath[8][i] = True
    onPath[i][0] = True
    onPath[i][8] = True

start_r = 1
start_c = 1

ans = try_path(0, start_r, start_c, p)

print(ans)

