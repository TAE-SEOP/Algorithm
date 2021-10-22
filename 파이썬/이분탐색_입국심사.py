# 입국심사 
"""
원하는 조건, 맞는 값, 탐색 범위를 먼저 생각하는 것이 좋은 듯
"""
def solution(n, times):
    answer = 0
    
    start = 0
    end = max(times) * n
    
    while(start <= end):
        p = 0
        mid = (start+end) // 2
        for t in times:
            if mid > t:
                p += (mid // t)
        if p >= n:
            answer = mid
            end = mid -1
        else:
            start = mid +1
        
    return answer


    