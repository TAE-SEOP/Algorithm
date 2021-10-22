import heapq
def solution(jobs):
    answer = 0
    jobs.sort()
    heap =[]
    now = jobs[0][0]
    last = -1
    cnt = 0
    while cnt < len(jobs):
        for i,j in jobs:
            if last < i <= now:
                heapq.heappush(heap,(j,i))
        if len(heap) != 0:
            cur = heapq.heappop(heap)
            cnt+=1
            last = now
            now += cur[0]
            answer += now - cur[1]
        else:
            now += 1
    return answer // len(jobs)

"""
대기하고 있는 것 중 작업 시간이 가장 짧은 순서대로 일을 진행 
일 도중에 요청된 작업은 대기해야함.
일이 끝난 후 대기 중인 작업 중 가장 짧은 것을 진행
heap을 사용하는데, 작업 시간으로 정렬한다.
"""