print("{0, ", end = '')
s = 1
for i in range(1, 62):
    s *= i
    for j in range(1, 997):
        if s * j % 997 == 1:
            print(j, end = ', ')
            break
print("}")