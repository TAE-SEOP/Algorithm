def solution(n, computers):
    answer = 0
    bfs = []
    visit = [0] * n
    
    for i in range(n):
        if visit[i] == 0:
            print(i)
            visit[i] = 1 
            bfs.append(i)
            while len(bfs) != 0:
                c = bfs.pop(0)
                for j in range(n):
                    if visit[j] == 0 and computers[c][j] == 1 and c != j:
                        bfs.append(j)
                        visit[j] = 1
            answer+=1
    
    return answer

    """
    그냥 bfs.....
    """