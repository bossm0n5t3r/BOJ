def sol():
    N = int(input())
    save = N
    cycle = 0
    while True:
        temp = (int(N / 10) + (N % 10)) % 10
        N = (N % 10) * 10 + temp
        cycle += 1
        if save == N:
            break
    print(cycle)


if __name__ == "__main__":
    sol()
