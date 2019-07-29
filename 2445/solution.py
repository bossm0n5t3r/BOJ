def sol():
    N = int(input())
    for i in range(2 * N - 1):
        if i < N:
            print('*' * (i + 1) + ' ' * 2 * (N - 1 - i) + '*' * (i + 1))
        else:
            print('*' * (2 * N - 1 - i) + ' ' * 2 * (i - N + 1) + '*' * (2 * N - 1 - i))


if __name__ == "__main__":
    sol()
