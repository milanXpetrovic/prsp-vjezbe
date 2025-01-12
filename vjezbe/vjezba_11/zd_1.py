#stick game
def stick_game(n, moves):
    dp = [False] * (n + 1)
    
    for i in range(1, n + 1):
        for move in moves:
            if i - move >= 0 and not dp[i - move]:
                dp[i] = True
                break
    
    result = ''.join('W' if dp[i] else 'L' for i in range(1, n + 1))
    print(result)

first_line = input()
n, k = map(int, first_line.split())
second_line = input()
moves = list(map(int, second_line.split()))

stick_game(n, moves)
