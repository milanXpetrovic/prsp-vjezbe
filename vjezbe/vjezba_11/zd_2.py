# nim_game I
def nim_game(t, test_cases):
    results = []
    
    for case in test_cases:
        n, heaps = case
        xor_sum = 0
        for heap in heaps:
            xor_sum ^= heap
        
        if xor_sum == 0:
            results.append("second")
        else:
            results.append("first")
    
    print("\n".join(results))

t = int(input())
test_cases = []

for _ in range(t):
    n = int(input())
    heaps = list(map(int, input().split()))
    test_cases.append((n, heaps))

nim_game(t, test_cases)
