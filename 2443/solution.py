def sol():
    N = int(input())
    for i in range(N):
        print(' ' * (i) + '*' * (2 * (N - i) - 1))


if __name__ == "__main__":
    sol()
