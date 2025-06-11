n = int(input())

s = input()
sl = s.split(" ")
a = []
for i in sl:
    a.append(int(i))


ronda = 1
while len(a) > 1:
    na = []
    elegido = False
    for i in range(0,len(a)):
        if i == len(a)-1:
            if not(elegido) and a[i] != ronda:
                na.append(a[i])
        elif a[i] == a[i+1] and not(elegido):
            na.append(a[i]*2)
            elegido = True
        elif a[i] != ronda and not(elegido):
            na.append(a[i])
            elegido = False
        else:
            elegido = False
    ronda *= 2
    a = na

print(a[0])