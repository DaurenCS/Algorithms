a,b = input().split()


def fun(s):
    x = []
    for i in s:
        
        if i == '#':
            x.pop()
        else:
            x.append(i)
    return x
            
if fun(a) == fun(b):
    print("Yes")
else:
    print("No")
        


