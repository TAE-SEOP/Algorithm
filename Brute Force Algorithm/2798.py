n,m = map(int,input().split())
a = list(map(int,input().split()))
hundred_flag = 0
ten_flag = 1
one_flag = 2
middle = 0
total = 0
while 1:
    middle = a[hundred_flag] + a[ten_flag] + a[one_flag]
    if middle <= m:
        if middle > total:
            total = middle
    if total == m:
        break
    if a[hundred_flag] == a[n-3] and a[ten_flag] == a[n-2] and a[one_flag] == a[n-1]:
        break
    elif a[one_flag] != a[n-1]:
        one_flag += 1
    elif a[one_flag] == a[n-1] and a[ten_flag] != a[n-2]:
        ten_flag += 1
        one_flag = ten_flag + 1
    elif a[one_flag] == a[n-1] and a[ten_flag] == a[n-2]:
        hundred_flag += 1
        ten_flag = hundred_flag + 1
        one_flag = ten_flag + 1
print(total)