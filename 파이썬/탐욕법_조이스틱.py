def solution(name):
    answer = 0
    cnt = []
    name = list(name)
    start = 'A' * len(name)
    
    for s,n in zip(start,name):
        tmp = ord(n) - ord(s)
        if tmp >= 13:
            tmp = 26 - tmp
        cnt.append(tmp)
        
    idx = 0
    
    while True:
        right = 1
        left = 1
        print(idx)
        name[idx] = 'A'
        if name == ["A"] * len(name): break
            
        for i in range(1,len(name)):
            if name[idx +i] == "A": right += 1
            else: break
                
        for i in range(1,len(name)):
            if name[idx -i] == "A": left += 1
            else: break
                
        if right > left:
            answer += left
            idx -= left
        else:
            answer += right
            idx += right
    

    answer += sum(cnt)
    
    """
    ex) "ZZAAAZZ" -> 8
                0 1 2 3 4 5 6 
                Z Z A A A Z Z
    
    idx         0 1         -1
    right       1 4          6
    left        1 2          1
    next_idx    1 -1        -2
    
    문자열을 리스트로 변환하면 인덱스로 좌 우측 이동을 쉽게 할 수 있다.
    
    """
    
                
    return answer