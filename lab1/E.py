n = 5
a = [int(n) for n in input().split(' ')]
b = [int(n) for n in input().split(' ')]




i = 0
c1 = 0

while True:
    if len(a) == 0 or len(b)==0 : 
        break
    elif c1>1000000:
        print("blin nichya")
        exit()
    if a[i]==0 and b[i]==9:
        a.append(a[i])
        a.append(b[i])
        b.pop(0)
        a.pop(0)
    elif b[i]==0 and a[i]==9:
        b.append(a[i])
        b.append(b[i])
        b.pop(0)
        a.pop(0)

    elif a[i] > b[i]:
        a.append(a[i])
        a.append(b[i])
        b.pop(0)
        a.pop(0)
        

    elif a[i] < b[i]:
        b.append(a[i])
        b.append(b[i])
        b.pop(0)
        a.pop(0)
    c1+=1

if a == []:
    print("Nursik ", c1)
else:
    print("Boris ", c1)




