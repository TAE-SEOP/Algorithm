def solution(p, l):
    answer = 0
    loc = [i for i in range(len(p))]
    result = {}
    prio = 1
    while len(p) != 0:
        if max(p) == p[0]:
            result[loc[0]] = prio
            prio += 1
            loc.pop(0)
            p.pop(0)
        else:
            p.append(p.pop(0))
            loc.append(loc.pop(0))
    answer = result[l]
    return answer


    