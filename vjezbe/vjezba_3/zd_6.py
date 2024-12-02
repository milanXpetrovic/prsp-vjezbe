def count_ways(board):
    cols = [False] * 8        
    diag1 = [False] * 15      
    diag2 = [False] * 15      

    def place_queen(row):
        if row == 8:  
            return 1
        ways = 0
        for col in range(8):
            if board[row][col] == '.' and not cols[col] and not diag1[row - col + 7] and not diag2[row + col]:
                cols[col] = diag1[row - col + 7] = diag2[row + col] = True
                ways += place_queen(row + 1)
                cols[col] = diag1[row - col + 7] = diag2[row + col] = False
        return ways

    return place_queen(0)

board = [input().strip() for _ in range(8)]
print(count_ways(board))
