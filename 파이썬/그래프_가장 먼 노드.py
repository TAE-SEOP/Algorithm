from collections import deque
def solution(n, edge):
    answer = 0
    visit = [0] * (n+1)
    grape ={}
    for e in edge:
        grape[e[0]] = grape.get(e[0],[]) + [e[1]]
        grape[e[1]] = grape.get(e[1],[]) + [e[0]]
    #print(grape)
    queue = deque()
    queue.append(1)
    visit[1] = 1
    while queue:
        nodes = len(queue)
        for i in range(nodes):
            current = queue.popleft()
            for c in grape[current]:
                if visit[c] == 0:
                    visit[c] = 1
                    #print(c)
                    queue.append(c)
    
    return nodes


    """
    bfs를 사용
    visit -> 방문 기록, grape -> 노드 간 연결, queue -> n번째 연결된 노드들을 저장하는...
    1. 모든 노드 간의 연결로 grape(dictionary)를 만든다.
    2. 1부터 시작, 1을 빼고 1과 연결된 노드들 queue에 넣는다.
    3. 해당 노드들을 방문한 적이 있다면 넣지 않고, 없다면 넣는다. -> 2와 3을 넣는다.
    4. 2와 3은 1로부터 거리가 1인 노드들
    5. 2,3과 연결된 노드들을 방문한 적이 없다면 queue에 저장
    6. queue에 저장된 4, 5, 6 은 1로부터 거리 2 떨어진 노드들
    7. 더 이상 방문한 적이 없고, 연결된 노드들이 없다면 while문 종료
    8. 이 때 마지막으로 queue의 길이가 저장된 nodes는 1로부터 가장 멀리 떨어진 노드들의 수가 된다. 
    """