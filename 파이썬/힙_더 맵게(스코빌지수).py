"""
첫 풀이 heapq 쓰지 않아서 효율성 테스트 통과 x
"""

def solution(scoville, K):
    answer = 0

    while len(scoville) > 1:
        if min(scoville) < K:
            answer +=1    
            first = scoville.pop(scoville.index(min(scoville)))
            second = scoville.pop(scoville.index(min(scoville)))
            scoville.append(first + second*2)
        else:
            scoville.pop()
    if scoville[0] < K:
        answer = -1
    return answer

"""
heapq사용
처음에 heappop사용하지 않고 그냥 pop을 사용했더니 힙 불변성이 유지되지 않아 틀렸었다.

heapq.heappush(heap, item)
힙 불변성을 유지하면서, item 값을 heap으로 푸시합니다.

heapq.heappop(heap)
힙 불변성을 유지하면서, heap에서 가장 작은 항목을 팝하고 반환합니다. 힙이 비어 있으면, IndexError가 발생합니다. 팝 하지 않고 가장 작은 항목에 액세스하려면, heap[0]을 사용하십시오.

heapq.heappushpop(heap, item)
힙에 item을 푸시한 다음, heap에서 가장 작은 항목을 팝하고 반환합니다. 결합한 액션은 heappush()한 다음 heappop()을 별도로 호출하는 것보다 더 효율적으로 실행합니다.

heapq.heapify(x)
리스트 x를 선형 시간으로 제자리에서 힙으로 변환합니다.

"""

import heapq

def solution(scoville, K):
    answer = 0
    heapq.heapify(scoville)
    
    while scoville[0] < K:
        if len(scoville) > 1:
            next = heapq.heappop(scoville) + heapq.heappop(scoville) * 2
            answer += 1
            heapq.heappush(scoville,next)
        else:
            return -1
    return answer
    