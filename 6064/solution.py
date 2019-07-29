import sys


def sol():
    read = sys.stdin.readline
    for _ in range(int(read())):
        M, N, x, y = [int(x) for x in read().split()]
        print(eea(M, N, x, y))


def e_gcd(x, y):
    s = [1, 0]
    t = [0, 1]
    r = [x, y]
    while r[-1] != 0:
        q = r[-2] // r[-1]
        r = [r[-1], r[-2] - q * r[-1]]
        s = [s[-1], s[-2] - q * s[-1]]
        t = [t[-1], t[-2] - q * t[-1]]
    return [r[0], s[0], t[0]]


def eea(M, N, x, y):
    gcd, s, t = e_gcd(M, N)
    if x % gcd != y % gcd:
        return -1
    else:
        return (x - M * s * (x - y) // gcd) % (M * N // gcd)


if __name__ == "__main__":
    sol()
