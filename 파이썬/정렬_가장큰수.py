def solution(numbers):
    answer = ''
    number = [str(num) * 3 for num in numbers]
    number.sort(reverse=True)
    
    for num in number:
        if num != "000":
            answer += str(num[:len(num)//3])
        else:
            answer += '0'
    if answer == "0" * len(numbers):
        answer = '0'
    return answer



    