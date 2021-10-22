# 징검다리
"""
바위를 n개 제거했을 때, 두 징검다리 사이의 거리의 최댓값을 구하라.
어느 것을 이분탐색할 것인가? -> 바위 사이의 거리
원하는 조건: n개의 바위 제거
가장 알맞은 값: 바위 사이 거리의 최솟값 중에 가장 큰 값
탐색 범위: 바위 사이의 거리?
start = 0 
end = distance (도착지점)
mid = ( start + end ) // 2  두 바위 사이의 거리를 가지고 이분탐색한다.
current를 통해 현재 바위의 위치를 표현



"""


def solution(distance, rocks, n):
    answer = 0
    rocks.sort()
    rocks.append(distance)
    
    start = 0
    end = distance
    
    while(start <= end):
        mid = (end + start) // 2
        current = 0
        cnt = 0
        md = float('inf')  # 무한
        for r in rocks:
            dif = r - current
            if mid > dif:
                cnt += 1
            else:
                current = r
                md = min(md,dif)
        if cnt > n:
            end = mid -1
        else:
            answer = md
            start = mid +1
    return answer