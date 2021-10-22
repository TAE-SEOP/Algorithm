def solution(phone_book):
    answer = True
    phone_book.sort()
    
    for i in range(len(phone_book)-1):
        if phone_book[i] == phone_book[i+1][:len(phone_book[i])]:
            return False

    return answer

"""
type이 문자열이어서 sort를 하면 바로 뒷 번호만 비교해도 되는 걸 생각하지 못함...
배씨가 알려줌..

"""
