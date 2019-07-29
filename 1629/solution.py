def sol():
    A, B, C = map(int, input().split())
    print(power(A, B, C))


def power(A, B, C):
    if B == 0:
        return 1 % C
    if B % 2 == 0:
        tmp = power(A, B // 2, C)
        return tmp * tmp % C
    else:
        tmp = power(A, (B - 1) // 2, C)
        return ( ( (A % C) * tmp ) * tmp ) % C


if __name__ == "__main__":
    sol()
