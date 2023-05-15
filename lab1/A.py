x = int(input())
a = []

for i in range(x):
    a.append(int(input()))

def fun(s):
    b = []
    
    x = s
    
    for j in range(s):
        b.insert(0,s)
        l = (len(b)-s)%len(b)
        b = b[l:] + b[:l]
        s-=1 
    return b
   

for i in a:
    print(*fun(i), sep=" ")
    
   