import math
x = int(input())

def fun(n):
    if n == 1:
        return False

    for i in range(2, (int)(math.sqrt(n))+1):
        
        if n % i == 0:
            return False
    return True

if fun(x):
    print("YES")
else:
    print("NO")
        



