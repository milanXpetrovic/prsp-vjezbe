def count_bits(n):
    count = 0
    i = 0
    while (1 << i) <= n:
        block_size = 1 << (i + 1)
        full_blocks = n // block_size
        count += full_blocks * (block_size // 2)
        remainder = n % block_size
        if remainder >= (block_size // 2):
            count += remainder - (block_size // 2) + 1
        i += 1
    return count

n = int(input().strip())

print(count_bits(n))
