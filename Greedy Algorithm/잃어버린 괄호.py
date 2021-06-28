list = input().split('-')
total_list = []

for i in list:
    temp = 0
    sum_list = i.split('+')
    for j in sum_list:
        temp += int(j)
    total_list.append(temp)
result = total_list[0]
for i in range(1,len(total_list)):
    result -= total_list[i]
    
print(result)