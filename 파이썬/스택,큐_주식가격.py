def solution(prices):
    answer = []
    stack = [0]
    for i in range(len(prices)-1,-1,-1):
        answer.append(i)
    
    for i in range(len(prices)):
        while stack and prices[stack[-1]] > prices[i]:
            idx = stack.pop()
            answer[idx] = i - idx
        stack.append(i)
    
    return answer

"""
stack -> LIFO
현재 위치에서 끝까지의 거리와 index를 이용
stack의 마지막 요소가 i번째보다 작으면 stack에 추가
stack의 마지막 요소가 i번째보다 크면 빼서 i - idx를 통해 떨어지지 않은 기간 체크
"""