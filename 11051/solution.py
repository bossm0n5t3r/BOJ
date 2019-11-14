def sol():
    N, K = map(int, input().split(" "))
    # pascal_tri = pascal(N)
    # print(pascal_tri[N][K])
    save = {0: 1, 1: 1}
    print((factorial(save, N) // factorial(save, K) // factorial(save, N - K)) % 10007)


def pascal(N):
    result = [[0 for j in range(1001)] for i in range(1001)]
    result[0][0] = 1
    result[1][0] = 1
    result[1][1] = 1
    for i in range(2, N + 1):
        result[i][0] = 1
        for j in range(1, i):
            result[i][j] = (result[i - 1][j - 1] + result[i - 1][j]) % 10007
        result[i][i] = 1
    return result


def factorial(save, N):
    if N not in save:
        save[N] = N * factorial(save, N - 1)
    return save[N]


if __name__ == "__main__":
    sol()
