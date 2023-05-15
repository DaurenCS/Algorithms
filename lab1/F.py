import math
x = int(input())

def fun(n):
    if n == 1:
        return False

    for i in range(2, (int)(math.sqrt(n))+1):
        
        if n % i == 0:
            return False
    return True

a = []
i = 1
while True:

    if fun(i):
        a.append(i)
        if len(a) == x and x<=1000:
            print(a[-1])
            exit()
    i+=1
        






