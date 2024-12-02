# weird algorithm

n = int(input())

while(n>0):

    if(n==1):
        print(int(n))
        break
    elif(n%2==0):
        print(int(n),end=" ")
        n = n/2
    else:
        print(int(n),end=" ")
        n = (n*3)+1