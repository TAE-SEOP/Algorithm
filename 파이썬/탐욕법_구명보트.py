def solution(people, limit):
    answer = 0
    people.sort(reverse=True)
    dict = {}
    list = {}
    for i in range(len(people)):
        flag = 0
        for j in range(len(dict)+1):
            if j not in dict.keys():
                dict[j] = 0
                list[j] = 0
            if dict[j] + people[i] <= limit and list[j] < 2:
                dict[j] += people[i]
                list[j] += 1
                flag = 1
                break
    answer = len(dict)
    return answer
    
    """
    답은 맞는데 효율성 테스트가 다 틀림
    이중for문을 사용해서...
    """

    from collections import deque

def solution(people, limit):
    answer = 0
    people.sort(reverse=True)
    
    de = deque(people)
    
    while de:
        if len(de) >= 2:
            if de[0] + de[-1] <= limit:
                de.pop()
                de.popleft()
                answer += 1
            elif de[0] + de[-1] > limit:
                de.popleft()
                answer += 1
        else:
            answer += 1
            de.pop()
    
    return answer

    """
    deque ->  양방향 큐로 앞, 뒤 양쪽 방향에서 엘리먼트(element)를 추가하거나 제거할 수 있다.
    어차피 2명 제한이기 때문에 deque를 이용해 2개씩 비교하고, 굳이 저장할 필요없이 answer의 수만 구하면 된다...?
    하..
    """