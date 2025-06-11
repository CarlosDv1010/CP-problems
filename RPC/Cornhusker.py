import math

s = input()
sl = s.split(" ")
a = []
for i in sl:
    a.append(int(i))

s2 = input()
sl2 = s2.split(" ")

n = int(sl2[0])
kwf = int(sl2[1])

sum = a[0]*a[1]
sum += a[2]*a[3]
sum += a[4]*a[5]
sum += a[6]*a[7]
sum += a[8]*a[9]

av = math.floor(sum / 5)

tot = (av * n) / kwf

print(math.floor(tot))