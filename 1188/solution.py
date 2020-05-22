def sol():
    N, M = map(int, input().split())
    print(M - gcd(N, M))


def gcd(x, y):
    while y:
        x, y = y, x % y
    return x


if __name__ == "__main__":
    sol()
