def solution(begin, target, words):
    answer = 0
    bfs = []
    if target not in words:
        return 0
    
    bfs.append(begin)
    
    while len(bfs) != 0:     # bfs가 빌 때까지
        for k in range(len(bfs)):   # 몇 번 바꿨는지 세기 위해 
            current = bfs.pop(0)
            for i in range(len(words)): # words내에 바꿀 수 있는 단어를 찾기 위해
                cnt = 0
                for j in range(len(begin)): # 비교하는 두 단어가 변환 가능한지 확인하기 위해
                    if current[j] == words[i][j]: cnt+=1
                    
                if cnt == len(begin)-1 and current != words[i] and words[i] not in bfs:  # 한글자만 바꿀 수 있고, bfs에 바꾸려는 단어가 없다 (중복 X)
                    bfs.append(words[i])
        answer += 1
        if target in bfs: break
        
        
    return answer


    """
    visit를 안 쓰고 중복만 안 생기게 모두 넣었다...
    왜 통과인거지..?
    """