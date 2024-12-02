import random

n = int(input())

numbers = []
for i in range(n):
    numbers.append(random.randrange(-10, 10))


for num in numbers:
    print(num, end=" ")