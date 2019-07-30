def sol(N, M, broken):
    N = int(N)
    broken = list(map(int, broken.split()))
    available = [str(n) for n in range(10) if n not in broken]
    available.sort()
    minimum = abs(N - 100)
    if len(available) == 0:
        return minimum
    if len(available) == 1 and available[0] == '0':
        return min(minimum, N + 1)
    glb = find_glb(str(N), 0, '', available)
    if glb:
        glb = str(int(glb))
        minimum = min(minimum, len(glb) + int(glb) - N)
    lub = find_lub(str(N), 0, '', available)
    if lub:
        lub = str(int(lub))
        minimum = min(minimum, len(lub) + N - int(lub))
    return minimum


def find_glb(findString, startIndex, resultString, available):
    if len(findString) <= startIndex:
        return resultString
    for i in available:
        if int(findString[0 : startIndex + 1]) <= int(resultString + i):
            r = find_glb(findString, startIndex + 1, resultString + i, available)
            if r:
                return r
    if startIndex == 0:
        return find_glb('0' + findString, startIndex, resultString, available)
    else:
        return None


def find_lub(findString, startIndex, resultString, available):
    if len(findString) <= startIndex:
        return resultString
    for i in reversed(available):
        if int(findString[0:startIndex+1]) >= int(resultString + i):
            r = find_lub(findString, startIndex + 1, resultString + i, available)
            if r:
                return r
    if startIndex == 0:
        return find_lub(findString, startIndex + 1, resultString, available)
    else:
        return None


if __name__ == "__main__":
    N = input()
    M = input()
    broken = ''
    if M != '0':
        broken = input()
    print(sol(N, M, broken))
