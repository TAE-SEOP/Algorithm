from collections import deque

def solution(b, w, t):
    answer = 0
    bridge = [0] * b
    time = 0
    
    while bridge:
        time+=1
        bridge.pop(0)
        if t:
            if t[0] + sum(bridge) <= w:
                bridge.append(t.pop(0))
            else:
                bridge.append(0)
    
    return time

"""
deque => 스택과 큐의 기능을 모두 가진 객체
"""

from collections import deque

def solution(b, w, t):
    answer = 0
    bridge = deque([0] * b)
    time = 0
    while bridge:
        time+=1
        bridge.popleft()
        if t:
            if t[0] + sum(bridge) <= w:
                bridge.append(t.pop(0))
            else:
                bridge.append(0)
    
    return time

"""
sum(bridge)로 인한 시간초과
current라는 변수를 bridge안의 트럭들 무게의 합을 구하는데 사용
"""

from collections import deque

def solution(b, w, t):
    answer = 0
    bridge = deque([0] * b)
    time = 0
    current = 0
    while bridge:
        time+=1
        current -= bridge.popleft()
        if t:
            if t[0] + current <= w:
                current += t[0]
                bridge.append(t.pop(0))
            else:
                bridge.append(0)
    
    return time