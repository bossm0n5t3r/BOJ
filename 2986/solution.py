def sol():
    N = int(input())
    i = 2
    while i * i <= N:
        if N % i == 0:
            print(N - (N // i))
            return
        i += 1
    print(N - 1)


if __name__ == "__main__":
    sol()
