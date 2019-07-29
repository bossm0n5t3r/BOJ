def sol():
    N = int(input())
    count = 0
    for i in range(1, N+1):
        if hansu(i):
            count += 1
    print(count)


def hansu(n):
    if n // 10 == 0:
        return True
    temp = list(map(int, str(n)))
    diff = []
    for i in range(len(temp) - 1):
        diff.append(temp[i+1] - temp[i])
    return len(set(diff)) == 1


if __name__ == "__main__":
    sol()
