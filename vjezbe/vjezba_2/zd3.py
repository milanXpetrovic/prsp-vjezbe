n = input()

longest = 1
maxL = 0
for i in range(len(n)):
    if(n[i-1] == n[i]):
        maxL = maxL+1
        longest = max(maxL, longest) 
    else:
        maxL = 1

print(longest)