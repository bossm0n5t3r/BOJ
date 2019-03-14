"""
Perfect square number

https://www.acmicpc.net/problem/1977
"""


def sol():
    m = int(input())
    n = int(input())
    candidate = []
    i = int(m**.5)
    while True:
        if m <= (i * i) <= n:
            candidate.append(i*i)
        elif (i * i) > n:
            break
        i += 1

    if len(candidate) != 0:
        print(sum(candidate))
        print(candidate[0])
    else:
        print(-1)


if __name__ == "__main__":
    sol()
