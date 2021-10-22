def solution(number, k):
    answer = ''
    stack =[]
    idx = 1
    stack.append(number[0])
    cnt = k
    while True:
        if len(stack) != 0 and k > 0:
            if stack[-1] < number[idx]:
                stack.pop(-1)
                k -= 1
            else:
                stack.append(number[idx])
                idx+=1
        else:
            stack.append(number[idx])
            idx+=1
            
        if idx >= len(number) or k < 0: 
            break
    answer = "".join(stack)
    if len(answer) != len(number)-cnt:           # 앞자리와 뒷자리의 숫자가 같아서 k만큼 빼지 못 했을 경우 뒤 숫자들을 잘라준다.
        answer = answer[:len(number)-cnt]
            
    return answer

    """
    stack에 넣으면서 stack의 마지막 요소가 새로 넣을 수보다 작으면 빼고 넣는다.
    """