from collections import defaultdict

def solution(n, results):
    answer = 0
    win = defaultdict(set)
    lose = defaultdict(set)
    
    for i, j in results:
        win[i].add(j)
        lose[j].add(i)
        
    for i in range(1,n+1):
        for loser in win[i]:
            lose[loser].update(lose[i])
        for winner in lose[i]:
            win[winner].update(win[i])
    
    for i in range(1,n+1):
        if len(win[i]) + len(lose[i]) == n-1:
            answer += 1
    
    print(win)
    print(lose)
    
    return answer


    """
    win[이긴 애] = 진 애
    lose[진 애] = 이긴 애

    A가 B를 이겼다면, A는 B한테 진 애들을 전부 이긴다. ->win[A] = B, win[A] += win[B]  
                                                     ->이렇게 표현할 수 있지만 for문에서 win[A]가 바뀌면 안되기 때문에 lose[B] = A, 를 대신 사용
    B가 A한테 졌다면, B는 A를 이긴 애들한테 전부 진다. ->lose[B] = A, lose[B] += lose[A]
                                                     ->마찬가지로 win[A] = B
    """