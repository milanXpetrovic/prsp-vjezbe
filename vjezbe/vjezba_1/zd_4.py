# way too long words

with open("ulaz.txt", "r") as file:
    data = file.readlines()

n = int(data[0].strip())

words = [line.strip() for line in data[1:n+1]]


for word in words:
    if len(word) > 10:
        print(word[0]+str(len(word)-2)+word[len(word)-1])
