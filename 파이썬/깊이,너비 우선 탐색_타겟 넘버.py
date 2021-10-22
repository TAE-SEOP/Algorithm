from collections import deque
def solution(numbers, target):
    answer = 0
    queue = deque()
    queue.append(numbers[0])
    queue.append(-numbers[0])
    
    for i in range (1,len(numbers)):
        for j in range (len(queue)):
            current = queue.popleft()
            queue.append(current + numbers[i])
            queue.append(current - numbers[i])
    answer = queue.count(target)
    
    return answer

    """
    deque를 이용...
    모든 경우를 다 deque에 넣고 deque에서 target인 것의 개수를 카운트...
    """