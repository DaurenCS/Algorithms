n = int(input())

x = [int(n) for n in input().split(' ')]
a = []
a.append(-1)
for i in range(1,n):
    for j in range(1,n):
        if x[i]>=x[i-j] and i-j>=0:
            a.append(x[i-j])
            break
        
        elif x[i]<x[i-j] and i-j>=0:
            continue
        else:
            a.append(-1)
            break
      


for i in a:
    print(i, end = ' ')



   


    

