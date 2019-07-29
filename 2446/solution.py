def sol():
    N = int(input())
    save = []
    for i in range(N, 0, -1):
        save.append(' ' * (N - i) + '*' * (2 * i - 1))
    for i in range(N):
        print(save[i])
    for i in range(N - 2, -1, -1):
        print(save[i])


if __name__ == "__main__":
    sol()
