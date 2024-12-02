seq = input()
coded = []
for s in seq:
    if s == "A":
        coded.append("00")
    if s == "B":
        coded.append("01")
    if s == "C":
        coded.append("10")
    if s == "D":
        coded.append("11")

for c in coded:
    print(c,end="")