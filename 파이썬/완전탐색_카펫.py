def solution(brown, yellow):
    answer = []
    t = brown + yellow
    for i in range(t,2,-1):
        if t % i == 0:
            a = t // i
            if yellow == (i-2)*(a-2):
                return [i,a]