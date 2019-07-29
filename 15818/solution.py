def sol():
    N, M = map(int, input().split())
    tmp = list(map(int, input().split()))
    result = 1
    for i in range(N):
        result = ( (result % M) * (tmp[i] % M) ) % M
    print(result)


if __name__ == "__main__":
    sol()
