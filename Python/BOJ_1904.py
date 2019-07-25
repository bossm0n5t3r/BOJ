'''
01 Tile

https://www.acmicpc.net/problem/1904
'''


def sol():
    N = int(input())
    a, b = (1,1,1,0), (1,0,0,1)
    while N > 0:
        if N & 1:
            b = mul(a, b)
        N >>= 1
        a = mul(a, a)
    print(b[0])


def mul(a, b):
    return (
        (a[0] * b[0] + a[1] * b[2]) % 15746,
        (a[0] * b[1] + a[1] * b[3]) % 15746,
        (a[2] * b[0] + a[3] * b[2]) % 15746,
        (a[2] * b[1] + a[3] * b[3]) % 15746
    )


if __name__ == "__main__":
    sol()
