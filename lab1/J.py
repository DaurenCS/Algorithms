a = []
b = []
while True:
    n = input().split(' ')

    if n[0] == '+':
        a.insert(0,n[-1])
        
    elif n[0] == '-':
        a.append(n[-1])
        
    elif n[0] == '*' and a == []:
        b.append("error")
    elif n[-1] == '!':
        break 
    elif n[0] == '*':
        b.append(int(a[0])+int(a[-1]))
        a.pop()
        if len(a)!=0:
            a.pop(0)
    
    
for i in b:
    print(i, end = '\n')

        


