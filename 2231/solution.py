def sol():
    N = int(input())
    for i in range(max(N - 54, N // 2), N):
        if i + sum_digits(i) == N:
            print(i)
            exit()
    print(0)


def sum_digits(n):
    s = 0
    while n:
        s += n % 10
        n //= 10
    return s


if __name__ == "__main__":
    sol()
