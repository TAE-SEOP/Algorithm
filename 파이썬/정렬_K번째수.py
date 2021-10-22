def solution(array, commands):
    answer = []
    for com in commands:
        arr = array[com[0]-1:com[1]]
        arr.sort()
        answer.append(arr[com[2]-1])
    return answer



    