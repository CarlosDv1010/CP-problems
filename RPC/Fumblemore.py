s = input()
invalid = False
if s[-1] == 'E':
    invalid = True
for i in range(1,len(s)):
    if s[i] == 'O' and s[i-1] == 'O':
        invalid = True
for i in range(len(s)):
    if s[i] not in "EO":
        invalid = True


if invalid: 
    print("INVALID")
else: 
    res = float("inf")
    for i in range(1,10000):
        prev = 2**i
        valid = True
        for j in reversed(range(len(s))):
            if not valid:
                break
            if s[j] == 'E':
                prev *= 2
            if s[j] == 'O':
                div = (prev - 1) // 3
                if (prev != 3*div + 1):
                    valid = False
                prev = div
            if (prev > 0 and (prev & (prev - 1)) == 0) or prev == 0:
                valid = False
                
        if valid:
            res = prev
            break
    if res == float("inf"):
        print("INVALID")
    else:
        print(res)