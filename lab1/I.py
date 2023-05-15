x = int(input())
s = input()
a = []

for i in s:
    a.append(i)

k = 0
s = 0


while True:

    if k>len(a) or s>len(a):
        break

    if a[0] == 'S' and s == 0:
        k+=1
        a.pop(0)
        a.append('S')
        
    elif a[0] == 'K' and k == 0:
        s+=1
        a.append('K')
        a.pop(0)
    elif a[0] == 'K' and k != 0:
        k-=1
        a.pop(0)
    elif a[0] == 'S' and s != 0:
        s-=1
        a.pop(0)
print(a)

if a[-1] == 'S':
    print("SAKAYANAGI")
else:
    print("KATSURAGI")





       
        


    










