def solution(n, lost, reserve):
    answer = 0
    cnt = 0
    lost.sort()
    for lo in lost:
        if lo in reserve:
            reserve.pop(reserve.index(lo))
            cnt += 1
        elif lo-1 in reserve:
            reserve.pop(reserve.index(lo-1))
            cnt += 1
        elif lo+1 in reserve and lo+1 not in lost:
            reserve.pop(reserve.index(lo+1))
            # reserve.remove(lo+1)   index찾아서 pop할 필요없이 remove()를 하면 list 내의 요소를 바로 삭제 가능
            cnt += 1
        answer = n - (len(lost) -cnt)
            
    
    return answer

    """
    처음에 이 조건을 고려하지 않음
    -> 여벌 체육복을 가져온 학생이 체육복을 도난당했을 수 있습니다. 이때 이 학생은 체육복을 하나만 도난당했다고 가정하며, 남은 체육복이 하나이기에 다른 학생에게는 체육복을 빌려줄 수 없습니다.
    
    문제에서 정렬이 안된 list에 대한 언급이 없었는데....이것도 고려해야 했다 

    """