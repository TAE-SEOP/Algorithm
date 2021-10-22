def solution(clothes):
    answer = 1
    a = {}
    for c in clothes:
        if c[1] in a:
            a[c[1]]+=1
        else:
            a[c[1]] = 1
    for i in a.values():
        answer *= i+1
    
    return answer-1
"""
각 부위별로 개수를 구하고 +1을 하여 곱함 -> 안 입는 경우까지 포함해야하기 때문에
마지막에 -1을 해준다. -> 모두 안 입는 경우는 빼야하므로
"""


from collections import Counter
from functools import reduce
def solution(clothes):
    
    
    cnt = Counter([k for name, k in clothes])
    answer = reduce(lambda x , y : x*(y+1), cnt.values(),1)-1
    print(cnt)
    return answer

"""
collection의 Counter함수를 사용하여 개수를 센다. 
누적 집계를 내기 위해 사용하는 functools의 reduce함수를 사용한다.

reduce(function, iterable, initializer=None)


"""