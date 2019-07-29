def sol():
    N = int(input())
    for i in range(2 * N - 1):
        if i < N:
            print(' ' * (N - 1 - i) + '*' * (2 * i + 1))
        else:
            print(' ' * (i - N + 1) + '*' * (4 * N - 3 - 2 * i))


if __name__ == "__main__":
    sol()
