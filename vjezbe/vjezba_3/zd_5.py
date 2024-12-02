def is_safe(row, col, queens):
    for r, c in queens:
        if c == col or r - c == row - col or r + c == row + col:
            return False
    return True

def solve_n_queens(n, row=0, queens=[]):
    if row == n:
        return 1 
    count = 0
    for col in range(n):
        if is_safe(row, col, queens):
            count += solve_n_queens(n, row + 1, queens + [(row, col)])
    return count

n = int(input())
print(solve_n_queens(n))
