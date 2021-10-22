def solution(citations):
    answer = 0
    citations.sort()
    start = 0
    end = citations[-1]
    
    if end == 1:
        return 1
    
    mid = (start + end) // 2
    
    while end != 0:
        cnt = 0
        for cit in citations:
            if mid <= cit:
                cnt+=1
        if mid <= cnt and mid >= len(citations) - cnt:
            answer = mid
            break
        elif mid > cnt:
            mid -= 1
        else:
            mid += 1
    return answer

"""
ciations[i] : 오름차순으로 정렬한 후, h번 인용된 논문
l-i : 전체 인용 수 - i 를 통해 h번 이상 인용한 논문의 수
도대체 이런 생각을 어떻게 하는거야...
"""
    
def solution(citations):
    citations = sorted(citations)
    l = len(citations)
    for i in range(l):
        if citations[i] >= l-i:
            return l-i
    return 0