    n=input()

x = []

    

for i in n:
    if len(x)==0:
        x.append(i)
        
    elif x[-1] == i:
        x.pop()
        
    else:
        x.append(i)

if x == []:
    print("YES")
else:
    print("NO")
        






    



