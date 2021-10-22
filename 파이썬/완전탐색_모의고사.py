"""처음"""
def solution(answers):
    answer = []
    first = [1,2,3,4,5]
    second = [2,1,2,3,2,4,2,5]
    third = [3,3,1,1,2,2,4,4,5,5]
    f_a = 0
    s_a = 0
    t_a = 0
    
    for i,a in enumerate(answers):
        f = i % 5
        s = i % 8
        t = i % 10
        if first[f] == a:
            f_a += 1
        if second[s] == a:
            s_a += 1
        if third[t] == a:
            t_a += 1
    max_answer = max(f_a,s_a,t_a)
    if max_answer == f_a:
        answer.append(1)
    if max_answer == s_a:
        answer.append(2)
    if max_answer == t_a:
        answer.append(3)    
    
    return answer

    """수정"""
def solution(answers):
    answer = []
    first = [1,2,3,4,5]
    second = [2,1,2,3,2,4,2,5]
    third = [3,3,1,1,2,2,4,4,5,5]
    check = [0,0,0]
    
    for i,a in enumerate(answers):
        if first[i % 5] == a:
            check[0] += 1
        if second[i % 8] == a:
            check[1] += 1
        if third[i % 10] == a:
            check[2] += 1

    for i,c in enumerate(check):
         if c == max(check):
             answer.append(i+1)
    
    return answer