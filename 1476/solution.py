def sol():
    E, S, M = map(int, input().split(" "))
    mod = 15 * 28 * 19
    z1 = 28 * 19
    z2 = 15 * 19
    z3 = 15 * 28
    y1 = inverse(z1, 15)
    y2 = inverse(z2, 28)
    y3 = inverse(z3, 19)
    w1 = (28 * 19 * 13) % mod
    w2 = (15 * 19 * 17) % mod
    w3 = (15 * 28 * 10) % mod
    x = (E * w1 + S * w2 + M * w3) % mod
    print(x if x else mod)


def inverse(a, n):
    for i in range(1, n):
        if (a * i) % n == 1:
            return i


if __name__ == "__main__":
    sol()
