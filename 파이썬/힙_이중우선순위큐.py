import heapq
def solution(oper):
    answer = []
    heap = []
    
    while len(oper) > 0:
        o = oper[0]
        oper.pop(0)
        if o[0] == 'I':
            heapq.heappush(heap,int(o[2:]))
        elif o[0] == 'D' and o[-2:] == "-1" and len(heap) != 0:
            heapq.heappop(heap)
        else:
            if len(heap) != 0:
                heap = heapq.nlargest(len(heap),heap)[1:]
                heapq.heapify(heap)
        
        
        
    if len(heap) != 0:
        answer.append(max(heap))  # 처음에 answer.append(heap[-1]) 로 최대값을 구하려고 하니 틀렸다. 
        answer.append(min(heap))  # heap은 우선순위가 1위 인것이 heap[0]인 것은 맞지만, 나머지에 대한 정렬은 보장하지 않기 때문이다. 
    else:
        answer.append(0)
        answer.append(0)
    return answer