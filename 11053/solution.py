def sol(N, seq):
    result = [seq[0]]
    index = 0
    for i in range(1, N):
        if result[index] < seq[i]:
            result.append(seq[i])
            index += 1
        else:
            for j in range(index + 1):
                if result[j] >= seq[i]:
                    result[j] = seq[i]
                    break
    index += 1
    return index


if __name__ == "__main__":
    N = int(input())
    seq = list(map(int, input().split()))
    print(sol(N, seq))
