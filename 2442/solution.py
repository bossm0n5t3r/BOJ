def sol():
    N = int(input())
    for i in range(N):
        print(' ' * (N - 1 - i) + '*' * (2 * i + 1))


if __name__ == "__main__":
    sol()
