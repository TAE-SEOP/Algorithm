number = int(input())
a = list()
for x in range(number):
    a.append(int(input()))
a.sort()
for y in range(number):
    print(a[y])