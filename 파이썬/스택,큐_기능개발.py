def solution(progresses, speeds):
    answer = []
    result =[]
    for i in range(len(progresses)):
        tmp = (100 - progresses[i]) // speeds[i]
        if (100 - progresses[i]) % speeds[i] != 0:
            tmp+=1
        result.append(tmp)
    
    tmp  = result[0]
    cnt = 1
    print(result)
    for i in range(len(result)):
        if tmp == 0:
            tmp = result[i]
        if i != len(result)-1:
            if tmp >= result[i+1]:
                cnt+=1
            else:
                answer.append(cnt)
                cnt = 1
                tmp = 0
    answer.append(cnt)
    return answer
"""
간단하게....
"""
def solution(progresses, speeds):
    answer = []
    days = 0
    cnt = 0
    
    while len(progresses) != 0:
        if progresses[0] + days * speeds[0] >= 100:
            cnt+=1
            progresses.pop(0)
            speeds.pop(0)
        else:
            if cnt > 0:
                answer.append(cnt)
                cnt=0
            days+=1
    
    answer.append(cnt)
    
    return answer