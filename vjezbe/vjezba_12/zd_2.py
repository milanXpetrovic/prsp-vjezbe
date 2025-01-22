MOD = int(1e9 + 7)
PRIMES = [31, 37, 43]

def compute_powers(M, primes):
    powers = [[1] * M for _ in range(len(primes))]
    for p in range(len(primes)):
        for i in range(1, M):
            powers[p][i] = (powers[p][i - 1] * primes[p]) % MOD
    return powers

def rolling_hash(S, T):
    N, M = len(S), len(T)
    if M > N:
        return 0

    powers = compute_powers(M + 1, PRIMES)
    sh, th = [0] * len(PRIMES), [0] * len(PRIMES)

    for i in range(M):
        for p in range(len(PRIMES)):
            sh[p] = (sh[p] + (ord(S[i]) - ord('a') + 1) * powers[p][M - i - 1]) % MOD
            th[p] = (th[p] + (ord(T[i]) - ord('a') + 1) * powers[p][M - i - 1]) % MOD

    def hashes_equal():
        return all(sh[p] == th[p] for p in range(len(PRIMES)))

    cnt = 1 if hashes_equal() else 0

    for i in range(M, N):
        for p in range(len(PRIMES)):
            sh[p] = (sh[p] * PRIMES[p] - (ord(S[i - M]) - ord('a') + 1) * powers[p][M] + (ord(S[i]) - ord('a') + 1)) % MOD
            sh[p] = (sh[p] + MOD) % MOD  
        if hashes_equal():
            cnt += 1

    return cnt

S = input().strip()
T = input().strip()
print(rolling_hash(S, T))
